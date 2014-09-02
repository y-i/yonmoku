#pragma once
#include "MyDef.h"
#include "DxLib.h"

class Board
{	// �΂�u���Ղ̃N���X
	int board[ROW+2][COLUMN+1];	// �㉺�E�ɔԕ�
	points mousePos;	// �}�E�X�̔Տ�̈ʒu
	int turn;	// ���
	Board() {}
	Board(const Board& r) {}
	Board& operator=(const Board& r) {}
	bool CheckBoardPoint(int player, int x, int y, int dx = 0, int dy = 0, 
		int count = 0);
	void PutIshi(points pos, int player);	// �Տ�̃f�[�^�ɐ΂�u��
public:
	static Board* getInstance() {
		static Board board;
		return &board;
	}
	void Init();	// �Ղ̏�����
	void SetPoint(points check, bool isPut = false);
	// �΂�u����ꏊ�̒����A�}�E�X�̍��W��Ղł̈ʒu�ɕϊ�
	bool IsWin(int player);	// ��������
	int GetBoard(int x, int y) const;
	int GetTurn() const;
	points GetMousePoint() const;
};
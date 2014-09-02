#pragma once
#include "MyDef.h"
#include "DxLib.h"

class Board
{	// 石を置く盤のクラス
	int board[ROW+2][COLUMN+1];	// 上下右に番兵
	points mousePos;	// マウスの盤上の位置
	int turn;	// 手番
	Board() {}
	Board(const Board& r) {}
	Board& operator=(const Board& r) {}
	bool CheckBoardPoint(int player, int x, int y, int dx = 0, int dy = 0, 
		int count = 0);
	void PutIshi(points pos, int player);	// 盤上のデータに石を置く
public:
	static Board* getInstance() {
		static Board board;
		return &board;
	}
	void Init();	// 盤の初期化
	void SetPoint(points check, bool isPut = false);
	// 石を置ける場所の調整、マウスの座標を盤での位置に変換
	bool IsWin(int player);	// 勝利判定
	int GetBoard(int x, int y) const;
	int GetTurn() const;
	points GetMousePoint() const;
};
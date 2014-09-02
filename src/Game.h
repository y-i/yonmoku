#pragma once
#include <vector>
#include "DxLib.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Board.h"
#include "MyDef.h"


class Game
{	// �Q�[���S��
	enum states { OPENING, PLAYING, ENDING } state;	// �Q�[���̏��
	// �C���X�^���X�̐錾
	Keyboard *key;
	Mouse *mouse;
	Board *board;
	int lineColor, turn, blackP, whiteP; 
	int goishiHandle[2], imgHandle[21], soundHandle[2];	// �f�[�^�̃n���h��
	Game() {}
	Game(const Game& r) {}
	Game& operator=(const Game& r) {}
	bool Calc();	// �v�Z�p
	void Draw();	// �`�ʗp
	void Reset();	// �f�[�^�������p
	void DrawBorder();	// �Ղ̉��̕`��
	void DrawIshi();	// �΂̕`��
	void DrawShadow(points pos);	// �u�����n�_�̉e�̕`��
	void DrawOpening();	// OP�̕`��
	void DrawPlayingMessage();	// �v���C���̏��̕`��
	void DrawEndingMessage();	// ED�̕`��
	void DrawScore();	// �X�R�A�̕`��
public:
	static Game* getInstance() {
		static Game game;
		return &game;
	}
	bool Init();	// �N���X�S�̂̏�����
	void Play();	// �Q�[���̃v���C�̊J�n
	void End();		// �I������

};
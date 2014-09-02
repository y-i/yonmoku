#pragma once
#include <vector>
#include "DxLib.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Board.h"
#include "MyDef.h"


class Game
{	// ゲーム全体
	enum states { OPENING, PLAYING, ENDING } state;	// ゲームの状態
	// インスタンスの宣言
	Keyboard *key;
	Mouse *mouse;
	Board *board;
	int lineColor, turn, blackP, whiteP; 
	int goishiHandle[2], imgHandle[21], soundHandle[2];	// データのハンドル
	Game() {}
	Game(const Game& r) {}
	Game& operator=(const Game& r) {}
	bool Calc();	// 計算用
	void Draw();	// 描写用
	void Reset();	// データ初期化用
	void DrawBorder();	// 盤の縁の描写
	void DrawIshi();	// 石の描写
	void DrawShadow(points pos);	// 置かれる地点の影の描写
	void DrawOpening();	// OPの描写
	void DrawPlayingMessage();	// プレイ中の情報の描写
	void DrawEndingMessage();	// EDの描写
	void DrawScore();	// スコアの描写
public:
	static Game* getInstance() {
		static Game game;
		return &game;
	}
	bool Init();	// クラス全体の初期化
	void Play();	// ゲームのプレイの開始
	void End();		// 終了処理

};
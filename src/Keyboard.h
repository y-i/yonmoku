#pragma once
#include "DxLib.h"

class Keyboard {	// キーボードのデータ
	int key[256];	// それぞれがキーボードの押されているフレーム数
	Keyboard() {}
	Keyboard(const Keyboard& r) {}
	Keyboard& operator=(const Keyboard& r) {}
public:
	static Keyboard* getInstance() {
		static Keyboard keyboard;
		return &keyboard;
	}
	void Keyboard_Init();	// 入力状態の初期化
	void Keyboard_Update();	// 入力状態を更新
	int Keyboard_Get(int);	// 入力状態を取得
};
#include "DxLib.h"
#include "Keyboard.h"

void Keyboard::Keyboard_Init() {	// 入力状態の初期化
	for (int i = 0; i < 256; i++) {
		key[i] = 0;
	}
}

void Keyboard::Keyboard_Update() {	// 入力状態を更新
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);  // 入力状態を取得
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) {
			key[i]++;
		} else {
			key[i] = 0;
		}
	}
}

int Keyboard::Keyboard_Get(int keycode) {	// 入力状態を取得
	return key[keycode]; // 入力状態を返す
}
#pragma once
#include "DxLib.h"
#include "MyDef.h"

class Mouse {	// マウスのデータ
	int mouseButton, prevMouseButton;	// マウスの現在の状態と1つ前の状態
	points pos;	// マウスの座標
	Mouse() {}
	Mouse(const Mouse& r) {}
	Mouse& operator=(const Mouse& r) {}
public:
	static Mouse* getInstance() {
		static Mouse mouse;
		return &mouse;
	}
	void Mouse_Update();	// 入力状態を更新
	bool Mouse_Get(int);	// 押されいるかどうか
	bool Mouse_Down(int);	// 今押したところかどうか
	bool Mouse_Up(int);		// 今離したところかどうか
	points GetMousePos();
};
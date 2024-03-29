#include "Mouse.h"

void Mouse::Mouse_Update() {	// 入力状態を更新
	prevMouseButton = mouseButton;
	mouseButton = GetMouseInput();
	GetMousePoint(&pos.x, &pos.y);
}

bool Mouse::Mouse_Get(int button) {	// 入力状態を取得
	return (mouseButton & button) && true; // 入力状態を返す
}

bool Mouse::Mouse_Down(int button) {
	return !(prevMouseButton & button) && (mouseButton & button);
}

bool Mouse::Mouse_Up(int button) {
	return (prevMouseButton & button) && !(mouseButton & button);
}

points Mouse::GetMousePos() {
	return pos;
}
#include "Mouse.h"

void Mouse::Mouse_Update() {	// ���͏�Ԃ��X�V
	prevMouseButton = mouseButton;
	mouseButton = GetMouseInput();
	GetMousePoint(&pos.x, &pos.y);
}

bool Mouse::Mouse_Get(int button) {	// ���͏�Ԃ��擾
	return (mouseButton & button) && true; // ���͏�Ԃ�Ԃ�
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
#include "Mouse.h"

void Mouse::Mouse_Update() {	// “ü—Íó‘Ô‚ğXV
	prevMouseButton = mouseButton;
	mouseButton = GetMouseInput();
	GetMousePoint(&pos.x, &pos.y);
}

bool Mouse::Mouse_Get(int button) {	// “ü—Íó‘Ô‚ğæ“¾
	return (mouseButton & button) && true; // “ü—Íó‘Ô‚ğ•Ô‚·
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
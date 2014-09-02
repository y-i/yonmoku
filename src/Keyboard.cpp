#include "DxLib.h"
#include "Keyboard.h"

void Keyboard::Keyboard_Init() {	// “ü—Íó‘Ô‚Ì‰Šú‰»
	for (int i = 0; i < 256; i++) {
		key[i] = 0;
	}
}

void Keyboard::Keyboard_Update() {	// “ü—Íó‘Ô‚ğXV
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);  // “ü—Íó‘Ô‚ğæ“¾
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) {
			key[i]++;
		} else {
			key[i] = 0;
		}
	}
}

int Keyboard::Keyboard_Get(int keycode) {	// “ü—Íó‘Ô‚ğæ“¾
	return key[keycode]; // “ü—Íó‘Ô‚ğ•Ô‚·
}
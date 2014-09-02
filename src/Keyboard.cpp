#include "DxLib.h"
#include "Keyboard.h"

void Keyboard::Keyboard_Init() {	// ���͏�Ԃ̏�����
	for (int i = 0; i < 256; i++) {
		key[i] = 0;
	}
}

void Keyboard::Keyboard_Update() {	// ���͏�Ԃ��X�V
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);  // ���͏�Ԃ��擾
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) {
			key[i]++;
		} else {
			key[i] = 0;
		}
	}
}

int Keyboard::Keyboard_Get(int keycode) {	// ���͏�Ԃ��擾
	return key[keycode]; // ���͏�Ԃ�Ԃ�
}
#pragma once
#include "DxLib.h"

class Keyboard {	// �L�[�{�[�h�̃f�[�^
	int key[256];	// ���ꂼ�ꂪ�L�[�{�[�h�̉�����Ă���t���[����
	Keyboard() {}
	Keyboard(const Keyboard& r) {}
	Keyboard& operator=(const Keyboard& r) {}
public:
	static Keyboard* getInstance() {
		static Keyboard keyboard;
		return &keyboard;
	}
	void Keyboard_Init();	// ���͏�Ԃ̏�����
	void Keyboard_Update();	// ���͏�Ԃ��X�V
	int Keyboard_Get(int);	// ���͏�Ԃ��擾
};
#pragma once
#include "DxLib.h"
#include "MyDef.h"

class Mouse {	// �}�E�X�̃f�[�^
	int mouseButton, prevMouseButton;	// �}�E�X�̌��݂̏�Ԃ�1�O�̏��
	points pos;	// �}�E�X�̍��W
	Mouse() {}
	Mouse(const Mouse& r) {}
	Mouse& operator=(const Mouse& r) {}
public:
	static Mouse* getInstance() {
		static Mouse mouse;
		return &mouse;
	}
	void Mouse_Update();	// ���͏�Ԃ��X�V
	bool Mouse_Get(int);	// �����ꂢ�邩�ǂ���
	bool Mouse_Down(int);	// ���������Ƃ��납�ǂ���
	bool Mouse_Up(int);		// ���������Ƃ��납�ǂ���
	points GetMousePos();
};
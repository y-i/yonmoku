#pragma once
//�e��萔��ݒ�
#define WIDTH 640	//��ʕ�
#define HEIGHT 480	//��ʂ̍���
#define SQSIZE 30	//1�}�X�̃T�C�Y
#define COLUMN 19	//��
#define ROW 10		//�s
#define FONT "ume-tgc5.ttf"	// �t�H���g�t�@�C���̈ʒu

enum { NONE, BLACK, WHITE };	// �}�X�̏��
typedef struct points {
	int x;
	int y;
} points;
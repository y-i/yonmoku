#pragma once
//各種定数や設定
#define WIDTH 640	//画面幅
#define HEIGHT 480	//画面の高さ
#define SQSIZE 30	//1マスのサイズ
#define COLUMN 19	//列
#define ROW 10		//行
#define FONT "ume-tgc5.ttf"	// フォントファイルの位置

enum { NONE, BLACK, WHITE };	// マスの状態
typedef struct points {
	int x;
	int y;
} points;
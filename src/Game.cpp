#include "Game.h"
#include "resource.h"

bool Game::Init() {	// initalize
	// DXƒ‰ƒCƒuƒ‰ƒŠŠÖŒW
	ChangeWindowMode(TRUE);
	SetMainWindowText("‚Í‚±‚Â‚Ý -Žl–Ú•À‚×");
	SetOutApplicationLogValidFlag(false);
	SetWindowSize(WIDTH, HEIGHT);
	SetBackgroundColor(240, 230, 140);
	SetUse3DFlag(FALSE);
	SetWindowSizeChangeEnableFlag(FALSE);
	SetWindowIconID(IDI_ICON1);
	if (DxLib_Init() == -1)	{
		return false;
	}
	// ƒQ[ƒ€‚Ìˆ—
	state = OPENING;
	//state = PLAYING;
	key = Keyboard::getInstance();
	mouse = Mouse::getInstance();
	board = Board::getInstance();
	lineColor = GetColor(32, 32, 32);
	LoadDivGraph("image/goisi.png", 21, 7, 3, 27, 27, imgHandle);
	goishiHandle[0] = imgHandle[1]; goishiHandle[1] = imgHandle[0];
	soundHandle[0] = LoadSoundMem("sound/se_maoudamashii_se_pc01.ogg");
	soundHandle[1] = LoadSoundMem("sound/se_maoudamashii_onepoint07.ogg");
	AddFontResourceEx(FONT, FR_PRIVATE, NULL);
	ChangeFont("”~ƒSƒVƒbƒNC5", DX_CHARSET_DEFAULT);
	blackP = whiteP = 0;
	Reset();

	return true;
}

void Game::Play() {
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		key->Keyboard_Update();
		mouse->Mouse_Update();
		if (!Calc()) { break; }
		Draw();
	}
}

void Game::End() {
	RemoveFontResourceEx(FONT, FR_PRIVATE, NULL);
	// DXƒ‰ƒCƒuƒ‰ƒŠŠÖŒW
	DxLib_End();	// ‚c‚wƒ‰ƒCƒuƒ‰ƒŠŽg—p‚ÌI—¹
}

bool Game::Calc() {
	//calculation
	// ó‘Ô‚Å•ªŠò
	switch (state) {
	case OPENING:
		if (key->Keyboard_Get(KEY_INPUT_Z) || mouse->Mouse_Up(MOUSE_INPUT_LEFT)) {
			state = PLAYING;
			SetFontSize(20);
		}
		break;
	case PLAYING:
		if (board->IsWin(BLACK) || board->IsWin(WHITE)) {
			PlaySoundMem(soundHandle[1], DX_PLAYTYPE_BACK);
			if (board->GetTurn() == BLACK) whiteP++;
			else if (board->GetTurn() == WHITE) blackP++;
			state = ENDING;
		} else if (mouse->Mouse_Up(MOUSE_INPUT_LEFT)) {
			board->SetPoint(mouse->GetMousePos(), true);
			PlaySoundMem(soundHandle[0], DX_PLAYTYPE_BACK);
		} else if (!mouse->Mouse_Get(MOUSE_INPUT_LEFT)) {
			board->SetPoint(mouse->GetMousePos(), false);
		}
		break;
	case ENDING:
		if (key->Keyboard_Get(KEY_INPUT_Z)) {
			state = PLAYING;
			board->Init();
		} else if (key->Keyboard_Get(KEY_INPUT_X)) {
			return false;
		}
		break;
	}
	return true;
}

void Game::Draw() {
	//draw
	SetDrawScreen(DX_SCREEN_BACK);
	// ó‘Ô‚Å•ªŠò
	switch (state) {
	case OPENING:
		DrawOpening();
		break;
	case PLAYING:
		DrawBorder();
		DrawIshi();
		DrawShadow(board->GetMousePoint());
		DrawPlayingMessage();
		break;
	case ENDING:
		DrawBorder();
		DrawIshi();
		DrawEndingMessage();
		break;
	}
}

void Game::DrawBorder() {
	for (int i = 0; i <= COLUMN; i++) {
		if (i == 0 || i == COLUMN) {
			DrawLine(35 + i * SQSIZE, 90 - 2, 35 + i * SQSIZE, 390 + 2, lineColor, 5);
		}
		else {
			DrawLine(35 + i * SQSIZE, 90, 35 + i * SQSIZE, 390, lineColor, 2);
		}
	}
	for (int i = 0; i <= ROW; i++) {
		if (i == 0 || i == ROW) {
			DrawLine(35 - 2, 90 + i * SQSIZE, 605 + 2, 90 + i * SQSIZE, lineColor, 5);
		}
		else {
			DrawLine(35, 90 + i * SQSIZE, 605, 90 + i * SQSIZE, lineColor, 2);
		}
	}
}

void Game::DrawIshi() {
	for (int i = 0; i < COLUMN; i++) {
		for (int j = 0; j < ROW; j++) {
			switch (board->GetBoard(i, j)) {
			case BLACK:
				DrawGraph(35 + 2 + SQSIZE * i, 90 + 2 + SQSIZE * j, goishiHandle[0], TRUE);
				break;
			case WHITE:
				DrawGraph(35 + 2 + SQSIZE * i, 90 + 2 + SQSIZE * j, goishiHandle[1], TRUE);
				break;
			}	
		}
	}
}

void Game::DrawShadow(points pos) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox(35 + SQSIZE * pos.x, 90 + SQSIZE * pos.y,
		35 + SQSIZE * (pos.x + 1), 90 + SQSIZE * (pos.y + 1),
		GetColor(135, 206, 235), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
}

void Game::DrawOpening() {
	DrawBox(150, 50, 490, 250, GetColor(32, 32, 32), FALSE);
	DrawFormatString(180, 120, GetColor(32, 32, 32), "‚Í ‚± ‚Â ‚Ý\n");
	DrawFormatString(140, 270, GetColor(96, 96, 96),
		"Press the Z key\n");
	DrawFormatString(300, 330, GetColor(96, 96, 96),
		"or\n");
	DrawFormatString(60, 390, GetColor(96, 96, 96),
		"Click the right button\n");
}

void Game::DrawPlayingMessage() {
	DrawFormatString(35, 10, GetColor(0, 0, 128),
		"%s‚ÌŽè”Ô‚Å‚·\n", board->GetTurn() == BLACK ? "•" : "”’");
	DrawScore();
}

void Game::DrawEndingMessage() {
	DrawFormatString(35, 10, GetColor(0, 0, 128),
		"‚à‚¤ˆê“x—V‚Ô‚É‚ÍZ‚ð");
	DrawFormatString(35, 30, GetColor(0, 0, 128),
		"ƒQ[ƒ€‚ðI—¹‚·‚é‚É‚ÍX‚ð‰Ÿ‚µ‚Ä‚­‚¾‚³‚¢");
	DrawScore();
}

void Game::DrawScore() {
	DrawFormatString(540, 10, GetColor(0, 0, 128), "•: %2d", blackP);
	DrawFormatString(540, 30, GetColor(0, 0, 128), "”’: %2d", whiteP);
}

void Game::Reset() {
	key->Keyboard_Init();
	board->Init();
	SetFontSize(48);
	turn = 0;
}
#include "DxLib.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Game *game = Game::getInstance();
	if (game->Init()) {
		game->Play();
		game->End();
	}

	return 0;				// ソフトの終了 
}

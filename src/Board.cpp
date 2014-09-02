#include "Board.h"

void Board::Init() {
	for (int i = 0; i < ROW+2; i++) {
		for (int j = 0; j < COLUMN+1; j++) {
			board[i][j] = NONE;
		}
	}
	turn = BLACK;
}

void Board::SetPoint(points check, bool isPut) {
	points tmp = mousePos;
	mousePos.x = (check.x - 35) / SQSIZE;
	mousePos.y = (check.y - 90) / SQSIZE;
	if (mousePos.x < 0 || mousePos.x >= COLUMN || mousePos.y < 0 || mousePos.y >= ROW) {
		mousePos = tmp;
	} else if (GetBoard(mousePos.x, mousePos.y) == NONE) {
		while (mousePos.y < ROW - 1 && GetBoard(mousePos.x, mousePos.y + 1) == NONE) mousePos.y++;
		if (isPut) {
			PutIshi(mousePos, turn);
			if (turn == BLACK) turn = WHITE;
			else if (turn == WHITE) turn = BLACK;
		}
	}
}

bool Board::IsWin(int player) {
	if (player != BLACK && player != WHITE) return false;
	for (int i = 0; i < COLUMN; i++)
		for (int j = 0; j < ROW; j++)
			if (CheckBoardPoint(player, i, j)) return true;
	return false;
}

int Board::GetBoard(int x, int y) const {
	return board[y+1][x+1];
}

int Board::GetTurn() const {
	return turn;
}

points Board::GetMousePoint() const {
	return mousePos;
}

bool Board::CheckBoardPoint(int player, int x, int y, int dx, int dy, 
	int count) {
	if (GetBoard(x,y) != player) return false;
	if (count == 4) return true;
	else if (count > 0) {
		return CheckBoardPoint(player, x+dx, y+dy, dx, dy, ++count);
	} else {
		return CheckBoardPoint(player, x, y, 0, 1, 1)
		|| CheckBoardPoint(player, x, y, 1, 0, 1)
		|| CheckBoardPoint(player, x, y, 1, 1, 1)
		|| CheckBoardPoint(player, x, y, 1, -1, 1);
	}
}

void Board::PutIshi(points pos, int player) {
	board[pos.y + 1][pos.x + 1] = player;
}
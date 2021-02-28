#include <Board.h>

#ifndef GAME
#define GAME

class Game {
public:
	Game();
	void start();

private:
	void selectPlayer();
	int getMove();
	int getAIMove();

	const char players[2] = { 'o', 'x' };
	bool isXTurn = false;
	Board board;
};

#endif

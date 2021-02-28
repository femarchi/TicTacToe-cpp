#include <iostream>
#include "Board.h"
#include "IOHelper.h"
#include "Game.h"

Game::Game() {
	this->board = Board();
}

void Game::selectPlayer(){
	printMsg("Select player char (x/o): ");
	char player;
	bool isValid = false;
	while (!isValid) {
		player = tolower(getChar());
		if (!(player == 'x' || player == 'o')) {
			printMsg("Invalid char, type x or o.");
		}
		else {
			isValid = true;
		}
	}
	std::string msg = "Player selected: ";
	msg.push_back(player);
	printMsg(msg);
	this->isXTurn = player == 'x';
}

int Game::getMove() {
	bool isValid = false;
	int move;
	while (!isValid) {
		move = getInt();
		isValid = board.isSquareAvailable(move);
		if (!isValid) {
			printMsg("Not a valid move, try again.");
		}
	}
	return move;
}

int Game::getAIMove() {
	int move = 0;
	do {
		move = std::rand() % 9 + 1;
	} while (!board.isSquareAvailable(move));
	return move;
}

void Game::start() {
	printMsg("Game started!");
	selectPlayer();
	board.print();
	bool gameEnd = false;
	int moves = 0;
	while (!gameEnd) {
		int currentMove = 0;
		char playerChar = players[isXTurn];
		if (moves%2) {
			printMsg("CPU moves");
			currentMove = getAIMove();
		}
		else {
			currentMove = getMove();
		}
		board.setCharAt(currentMove, playerChar);
		moves++;
		board.print();
		if (board.hasThreeInARow()) {
			std::string msg = "Player  Wins";
			msg.insert(7, 1, playerChar);
			printMsg(msg);
			gameEnd = true;
		} else if (moves >= 9) {
			printMsg("It's a draw.");
			gameEnd = true;
		}
		isXTurn = !isXTurn;
	}
}

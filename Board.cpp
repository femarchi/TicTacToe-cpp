#include <string>
#include "IOHelper.h"
#include "Board.h"

Board::Board() {
	reset();
}

void Board::reset() {
	int asciiOne = 49;
	for (int i = 0; i < 9; i++) {
		squares[i] = asciiOne + i;
	}
}

void Board::print() const {
	for (int i = 0; i < 9; i++) {
		printChar(squares[i]);
		if ((i+1) % 3 != 0) {
			printStr(" | ");
		}
		if (i == 2 || i == 5) {
			nextLine();
			printStr("----------");
			nextLine();
		}
	}
	nextLine();
}

void Board::setCharAt(int pos, char c) {
	char* square = &squares[pos - 1];
	*square = c;
}

char Board::getCharAt(int pos) const {
	return squares[pos - 1];
}

bool Board::isSquareAvailable(int pos) const {
	if (pos < 1 || pos > 9) {
		return false;
	}
	if (squares[pos - 1] > 58) { // chosen position is taken
		return false;
	}
}

bool Board::checkThree(int startPos, int step) const {
	for (int i = 1; i <= 2; i++) {
		if (squares[startPos] != squares[startPos + (i * step)]) {
			return false;
		}
	}
	return true;
}

bool Board::hasThreeInARow() const {
	// rows
	for (int i = 0; i < 3; i += 3) {
		if (checkThree(i, 1)) {
			return true;
		};
	}
	// cols
	for (int i = 0; i < 3; i++) {
		if (checkThree(i, 3)) {
			return true;
		}
	}
	// diags
	if (checkThree(0, 4) || checkThree(2, 2)) {
		return true;
	}

	return false;
}

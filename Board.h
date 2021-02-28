#ifndef BOARD_H	
#define BOARD_H

class Board {
public:
	Board();
	void reset(void);
	void print(void) const;
	void setCharAt(int pos, char playerMove);
	bool isSquareAvailable(int pos) const;
	char getCharAt(int pos) const;
	bool hasThreeInARow() const;
private:
	char squares[9];
	bool checkThree(int startPos, int incr) const;
};

#endif

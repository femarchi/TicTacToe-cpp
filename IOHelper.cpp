#include <iostream>
#include <string>

void printMsg(std::string msg) {
	std::cout << msg << std::endl;
}

void printStr(std::string msg) {
	std::cout << msg;
}

char getChar() {
	std::string input;
	std::getline(std::cin, input);
	char c{};
	if (input.length() > 0) {
		c = input[0];
	}
	return c;
}

void printChar(char c) {
	std::cout << c;
}

void nextLine() {
	std::cout << std::endl;
}

int getInt() {
	int n;
	bool isValid = false;
	while (!isValid) {
		printMsg("Input a number from 1 to 9");
		isValid = !!(std::cin >> n);
		if (!isValid) {
			printMsg("Not valid!");
		}
		std::cin.clear();
		std::cin.ignore(1, '\n');
	}

	return n;
}




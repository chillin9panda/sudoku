#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>

class sudoku{
private:
public:
	int linearSearch(int list[], int value);
	int binarySearch(int list[], int value);
	void displayBoard(int board[3][3][3][3]);
};


#endif

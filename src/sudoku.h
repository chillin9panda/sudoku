#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>

class sudoku {
private:
public:
  int verticalLinearSearch(int list[3][3][3][3], int value);
  int binarySearch(int list[], int value);
  void displayBoard(int board[9][9], int cursor[2]);
  void moveCursor(int cursor[2], char input);
  void insertValue(int board[9][9], int row, int column, int value);
};

#endif

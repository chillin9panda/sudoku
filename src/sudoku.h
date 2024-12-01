#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>

class sudoku {
private:
public:
  int verticalLinearSearch(int list[3][3][3][3], int value);
  int binarySearch(int list[], int value);
  void displayBoard(int board[3][3][3][3], int cursor[4]);
  void moveCursor();
  void insertValue(int board[3][3][3][3], int gridRow, int gridColumn, int row,
                   int column, int value);
};

#endif

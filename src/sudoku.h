#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>

class sudoku {
private:
public:
  void displayBoard(int board[9][9], int cursor[2]);
  void moveCursor(int cursor[2], char input);
  void insertValue(int board[9][9], int row, int column, int value);
  bool verticalLinearSearch(int board[9][9], int col, int value, int skipRow);
  bool horizontalLinearSearch(int board[9][9], int row, int value, int skipCol);
  bool gridSearch(int board[9][9], int startRow, int startCol, int value,
                  int skipRow, int skipCol);
  bool isValidPlacement(int board[9][9], int row, int col, int value);
  bool isWon(int board[9][9]);
  void difficultySwitch(int difficulty[9][9], int board[9][9]);
};

#endif

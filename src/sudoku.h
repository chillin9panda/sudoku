#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>

class sudoku {
private:
public:
  int verticalLinearSearch(int list[3][3][3][3], int value);
  int binarySearch(int list[], int value);
  void displayBoard(int board[3][3][3][3], int cursor[4]);
  void moveCursor(int &gridRow, int &gridColumn, int &row, int &column, char input);
  void insertValue(int board[3][3][3][3], int gridRow, int gridColumn, int row,
                   int column, int value);

  // board sectioning
  void grid1(int board[3][3][3][3], int grid_00[3][3]);
  void grid2(int board[3][3][3][3], int grid_01[3][3]);
  void grid3(int board[3][3][3][3], int grid_02[3][3]);
  void grid4(int board[3][3][3][3], int grid_10[3][3]);
  void grid5(int board[3][3][3][3], int grid_11[3][3]);
  void grid6(int board[3][3][3][3], int grid_12[3][3]);
  void grid7(int board[3][3][3][3], int grid_20[3][3]);
  void grid8(int board[3][3][3][3], int grid_21[3][3]);
  void grid9(int board[3][3][3][3], int grid_22[3][3]);
};

#endif

#ifndef SUDOKU_H
#define SUDOKU_H

#include <chrono>
#include <iostream>

class sudoku {
private:
  std::chrono::steady_clock::time_point startTime;
  std::chrono::steady_clock::time_point endTime;

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
  void assignDifficulty(int source[9][9], int destination[9][9]);
  void difficultySwitch(int board[9][9]);
  void startTimer();
  void stopTimer();
};

#endif

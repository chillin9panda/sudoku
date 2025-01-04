#ifndef SUDOKU_H
#define SUDOKU_H

#include "score.h"
#include <atomic>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <ostream>
#include <thread>
#include <unistd.h>

class sudoku {
private:
  // difficulty
  char difficulty;

  // Timer
  std::chrono::steady_clock::time_point startTime;
  std::chrono::steady_clock::time_point endTime;
  std::atomic<bool> liveTimer;

  double elapsedTime;

  // score object
  score points;
  double scoredPoint = 0;
  double totalPoints = 0;

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
  bool isValid(int board[9][9], int row, int col, int num);
  bool generateBoard(int board[9][9], int row, int col);
  void removeNumbers(int board[9][9], int emptyCell);
  void assignDifficulty(int source[9][9], int destination[9][9]);
  void difficultySwitch(int board[9][9]);
  void startTimer();
  void stopTimer();
  double calculateScore(char difficulty);

  // setters and getters
  void setDifficulty(char difficulty);
  char getDifficulty();
};

#endif

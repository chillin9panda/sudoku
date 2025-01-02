#include "sudoku.h"
#include <chrono>
#include <iomanip>
#include <ostream>
#include <thread>

// show board as 9x9 on console and cursor starts at specified position in
// main.cpp
void sudoku::displayBoard(int board[9][9], int cursor[2]) {
  for (int row = 0; row < 9; row++) {            //  row
    for (int column = 0; column < 9; column++) { // column
      if (row == cursor[0] && column == cursor[1]) {
        std::cout << "[" << board[row][column] << "]"
                  << "   ";
      } else {
        std::cout << board[row][column] << "   ";
      }
    }
    std::cout << "\n" << std::endl;
  }
}

// insert/change value at the position of the cursor
void sudoku::insertValue(int board[9][9], int row, int column, int value) {
  board[row][column] = value;
}

// Move cursor arround the board
void sudoku::moveCursor(int cursor[2], char input) {
  if ('w' == input && cursor[0] > 0) // Move up
    cursor[0]--;
  if ('s' == input && cursor[0] < 8) // Move Down
    cursor[0]++;
  if ('a' == input && cursor[1] > 0) // Move left
    cursor[1]--;
  if ('d' == input && cursor[1] < 8) // Move Right
    cursor[1]++;
}

// Searching Algorithms
// vertical search for the inserted value
bool sudoku::verticalLinearSearch(int board[9][9], int col, int value,
                                  int skipRow) {
  for (int row = 0; row < 9; row++) {
    if (row == skipRow || 0 == value) {
      continue;
    }

    if (value == board[row][col]) {
      return true; // Found
    }
  }

  return false; // Not fouund
}

// Horizontal value for the inserted value
bool sudoku::horizontalLinearSearch(int board[9][9], int row, int value,
                                    int skipCol) {
  for (int col = 0; col < 9; col++) {
    if (col == skipCol || 0 == value) {
      continue;
    }

    if (value == board[row][col]) {
      return true; // Found
    }
  }

  return false; // Not found
}

// Search within the grid of 3x3
bool sudoku::gridSearch(int board[9][9], int startRow, int startCol, int value,
                        int skipRow, int skipCol) {

  int currentRow, currentCol;

  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      currentRow = startRow + row;
      currentCol = startCol + col;

      if ((currentRow == skipRow && currentCol == skipCol) || 0 == value) {
        continue;
      }

      if (value == board[currentRow][currentCol]) {
        return true; // Found
      }
    }
  }
  return false; // Not found
}

// check placememnt with the search Algorithms
bool sudoku::isValidPlacement(int board[9][9], int row, int col, int value) {
  int startRow = row - row % 3; // Top lefy row of the grid
  int startCol = col - col % 3; // Top left column of the grid

  return !horizontalLinearSearch(board, row, value, col) &&
         !verticalLinearSearch(board, col, value, row) &&
         !gridSearch(board, startRow, startCol, value, row, col);
}

// Checks if the game is won
bool sudoku::isWon(int board[9][9]) {
  // Check rows and column for completeness
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (0 == board[row][col]) {
        return false;
      }
    }
  }

  // If all cells are filled and no 0 is left
  return true;
}

// assign one array to another
void sudoku::assignDifficulty(int source[9][9], int destination[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      destination[i][j] = source[i][j];
    }
  }
}

// switch to selected difficulty board to main board
void sudoku::difficultySwitch(int board[9][9]) {
  system("clear");

  // easy mode board
  int easy[9][9] = {
      {9, 4, 6, 3, 7, 1, 5, 0, 0}, {0, 7, 2, 9, 5, 0, 4, 6, 1},
      {8, 0, 5, 0, 6, 0, 3, 9, 7}, {0, 0, 0, 0, 1, 5, 0, 0, 0},
      {0, 0, 0, 0, 0, 2, 8, 1, 4}, {1, 0, 8, 4, 0, 0, 9, 0, 6},
      {4, 0, 0, 7, 0, 6, 0, 8, 0}, {0, 6, 9, 0, 0, 0, 0, 0, 0},
      {7, 8, 0, 5, 0, 0, 0, 3, 2},
  };

  // medium difficulty board
  int medium[9][9] = {
      {0, 0, 2, 0, 7, 1, 0, 6, 0}, {0, 3, 0, 0, 0, 8, 0, 7, 9},
      {4, 7, 6, 9, 0, 2, 8, 0, 0}, {0, 6, 9, 8, 0, 0, 5, 4, 2},
      {2, 0, 0, 6, 0, 5, 3, 8, 0}, {0, 0, 8, 7, 2, 4, 0, 0, 6},
      {1, 0, 7, 3, 0, 0, 6, 5, 4}, {6, 4, 3, 0, 0, 7, 0, 0, 0},
      {0, 9, 0, 0, 0, 0, 0, 3, 0},
  };

  // hard difficulty board
  int hard[9][9] = {
      {0, 3, 0, 8, 2, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {8, 0, 0, 5, 7, 0, 0, 1, 0}, {7, 0, 0, 2, 0, 0, 0, 0, 9},
      {0, 1, 0, 9, 8, 0, 0, 3, 0}, {6, 0, 0, 0, 0, 0, 0, 8, 4},
      {5, 9, 0, 0, 0, 0, 6, 0, 0}, {0, 0, 2, 0, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 7, 0, 0},
  };

  char difficultyOption;

  std::cout << "Difficulty Options" << std::endl;
  std::cout << "1. Easy\n" << "2. Medium\n" << "3. Hard" << std::endl;
  std::cout << "Select difficulty: ";
  std::cin >> difficultyOption;

  // set difficulty
  difficulty = difficultyOption;

  switch (difficultyOption) {
  case '1': {
    assignDifficulty(easy, board);
    break;
  }
  case '2': {
    assignDifficulty(medium, board);
    break;
  }
  case '3': {
    assignDifficulty(hard, board);
    break;
  }
  default: {
    std::cout << "Invalid Option" << std::endl;
  }
  }
}

// Game timer
// start timer
void sudoku::startTimer() {
  liveTimer = true;
  startTime = std::chrono::steady_clock::now();

  std::thread([this]() {
    while (liveTimer) {
      auto now = std::chrono::steady_clock::now();
      auto elapsedSeconds =
          std::chrono::duration_cast<std::chrono::duration<double>>(now -
                                                                    startTime);
      elapsedTime = elapsedSeconds.count();

      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  }).detach();
}

// stop timer
void sudoku::stopTimer() {
  liveTimer = false;
  endTime = std::chrono::steady_clock::now();
  auto elapsedSeconds =
      std::chrono::duration_cast<std::chrono::duration<double>>(endTime -
                                                                startTime);
  elapsedTime = elapsedSeconds.count();

  std::cout << "\rTime Elapsed: " << std::fixed << std::setprecision(2)
            << elapsedTime << " Seconds" << std::flush;
}

// Scoring
double sudoku::calculateScore(char difficulty) {
  switch (difficulty) {
  case '1': {
    scoredPoint = points.easyModePoints(elapsedTime);
    break;
  }
  case '2': {
    scoredPoint = points.mediumModePoints(elapsedTime);
    break;
  }
  case '3': {
    scoredPoint = points.hardModePoints(elapsedTime);
    break;
  }
  default: {
    std::cout << "Invalid Option" << std::endl;
  }
  }

  totalPoints += scoredPoint;

  return totalPoints;
}

// setters and getters
void sudoku::setDifficulty(char diff) { difficulty = diff; }

char sudoku::getDifficulty() { return difficulty; }

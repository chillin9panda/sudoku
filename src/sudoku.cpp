#include "sudoku.h"

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

// loads seected difficulty board to main board
void sudoku::difficultySwitch(int difficulty[9][9], int board[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      board[i][j] = difficulty[i][j];
    }
  }
}

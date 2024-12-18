#include "sudoku.h"

int sudoku::verticalLinearSearch(int list[3][3][3][3], int value) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          if (value != list[0][1][k][1] || value != list[2][1][k][1])
            return value;
        }
      }
    }
  }
  return -1;
}

void sudoku::displayBoard(int board[9][9], int cursor[2]) { //  row, column
  for (int row = 0; row < 9; row++) {                       //  row
    for (int column = 0; column < 9; column++) {            // column
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

void sudoku::insertValue(int board[9][9], int row, int column, int value) {
  board[row][column] = value;
}

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

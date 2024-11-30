#include "sudoku.h"

int sudoku::linearSearch(int list[], int value) {
  for (int i = 0; i < 9; i++) {
    if (value != list[i])
      return i;
  }
  return -1;
}


void sudoku::displayBoard(int board[3][3][3][3]) { // grid row, grid column, row, column
  for (int gridRow = 0; gridRow < 3; gridRow++) {            //  grid Row
    for (int gridColumn = 0; gridColumn < 3; gridColumn++) { //  grid column
      for (int row = 0; row < 3; row++) {                    //  row
        for (int column = 0; column < 3; column++) {         // column
          std::cout << board[gridRow][gridColumn][row][column] << " ";
        }
        if (gridColumn < 3)
          std::cout << "|";
      }
      std::cout << "\n";
    }
    if (gridRow < 2)
      std::cout << "---------------------" << std::endl;
  }
}

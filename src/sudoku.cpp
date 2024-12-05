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

void sudoku::displayBoard(int board[3][3][3][3],
                          int cursor[4]) { // grid row, grid column, row, column
  for (int gridRow = 0; gridRow < 3; gridRow++) {            //  grid Row
    for (int gridColumn = 0; gridColumn < 3; gridColumn++) { //  grid column
      for (int row = 0; row < 3; row++) {                    //  row
        for (int column = 0; column < 3; column++) {         // column
          if (gridRow == cursor[0] && gridColumn == cursor[1] &&
              row == cursor[2] && column == cursor[3]) {
            std::cout << "[" << board[gridRow][gridColumn][row][column] << "]"
                      << " ";
          } else {
            std::cout << board[gridRow][gridColumn][row][column] << " ";
          }
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

void sudoku::insertValue(int board[3][3][3][3], int gridRow, int gridColumn,
                         int row, int column, int value) {
  board[gridRow][gridColumn][row][column] = value;
}

void sudoku::moveCursor(int &gridRow, int &gridColumn, int &row, int &column,
                        char input) {

  switch (input) {
  case 'w': {
    if (row > 0) {
      row--;
    } else if (gridRow > 0) {
      gridRow--;
      row = 2;
    }
    break;
  }
  case 's': {
    if (row < 2) {
      row++;
    } else if (gridColumn < 0) {
      gridRow++;
      row = 0;
    }
    break;
  }
  case 'a': {
    if (column > 0) {
      column--;
    } else if (gridColumn > 0) {
      gridColumn--;
      column = 2;
    }
    break;
  }
  case 'd': {
    if (column < 2) {
      column++;
    } else if (gridColumn < 2) {
      gridColumn++;
      column = 0;
    }
    break;
  }

  default:
    std::cout << "Invalid input use w a s d to move, insert numbers 1-9\n";
  }
}

/*
// sectioning

void sudoku::grid1(int board[3][3][3][3], int grid_00[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      grid_00[i][j] = board[0][0][i][j];
    }
  }
}

void sudoku::grid2(int board[3][3][3][3], int grid_01[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      grid_01[i][j] = board[0][1][i][j];
    }
  }
}

void sudoku::grid3(int board[3][3][3][3], int grid_02[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      grid_02[i][j] = board[0][2][i][j];
    }
  }
}

void sudoku::grid4(int board[3][3][3][3], int grid_10[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      grid_10[i][j] = board[1][0][i][j];
    }
  }
}

void sudoku::grid5(int board[3][3][3][3], int grid_11[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      grid_11[i][j] = board[1][1][i][j];
    }
  }
}

void sudoku::grid6(int board[3][3][3][3], int grid_12[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      grid_12[i][j] = board[1][2][i][j];
    }
  }
}

void sudoku::grid7(int board[3][3][3][3], int grid_20[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      grid_20[i][j] = board[2][0][i][j];
    }
  }
}

void sudoku::grid8(int board[3][3][3][3], int grid_21[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      grid_21[i][j] = board[2][1][i][j];
    }
  }
}

void sudoku::grid9(int board[3][3][3][3], int grid_22[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      grid_22[i][j] = board[2][2][i][j];
    }
  }
}
*/

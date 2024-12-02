#include "sudoku.h"

  
int sudoku::verticalLinearSearch(int list[3][3][3][3], int value){
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j< 3; j++){
        for (int k=0; k<3; k++){
            for (int l=0;l<3;l++){
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


void sudoku::moveCursor(){

}


#include <iostream>

void displayBoard(int board[3][3][3][3]) { // grid row, grid column, row, column
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

int main() {
  int board[3][3][3][3] = {{{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
                            {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
                            {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}},

                           {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
                            {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
                            {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}},

                           {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
                            {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
                            {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}}};

  board[1][1][1][1] = 5;

  displayBoard(board);

  return 0;
}

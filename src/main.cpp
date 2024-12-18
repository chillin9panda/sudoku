#include "sudoku.h"
#include <iostream>

int main() {
  int board[9][9] = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
  };

  sudoku game;

  int cursor[2] = {0, 0};
  game.insertValue(board, 4, 5, 5);

  // int x = game.verticalLinearSearch(board, 5);

  char input;
  int value;

  while (true) {
    system("clear"); // cls for windows

    std::cout << " Use w, a, s, d to move \n i to insert value q \n to quit :\n"
              << std::endl;

    game.displayBoard(board, cursor);

    std::cin >> input;

    if ('q' == input) {
      break;
    }

    if ('i' == input) {
      std::cin >> value;
      game.insertValue(board, cursor[0], cursor[1], value);
    }

    game.moveCursor(cursor, input);
  }

  return 0;
}

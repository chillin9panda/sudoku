#include "sudoku.h"

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

  while (true) {
    system("clear"); // cls for windows

    std::cout << "Use w, a, s, d to move and q to quit.\n" << std::endl;

    game.displayBoard(board, cursor);

    std::cin >> input;

    if ('q' == input) {
      break;
    }

    game.moveCursor(cursor, input);
  }

  return 0;
}

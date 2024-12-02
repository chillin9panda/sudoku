#include "sudoku.h"

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

  sudoku game;
  
  int cursor[4] = {0, 0, 0, 0};
  game.insertValue(board, 1, 1, 1, 1, 5);

  game.displayBoard(board, cursor);
  int x = game.verticalLinearSearch(board, 5);
  std::cout<<"\n"<<x;
  return 0;
}

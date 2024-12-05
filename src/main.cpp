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

  // int x = game.verticalLinearSearch(board, 5);

  char input;
  
  while(true){
    game.displayBoard(board, cursor);
   

    std::cin >> input;

    if ('q'==input){
      break;
    }

    game.moveCursor(cursor[0], cursor[1], cursor[2], cursor[3], input);
  }


  return 0;
}

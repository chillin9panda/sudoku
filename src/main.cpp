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
  int value;

  while (true) {
    system("clear"); // use "cls" for windows

    std::cout << " Use w, a, s, d to move\n"
              << " i to insert value\n"
              << " q to quit\n"
              << std::endl;

    game.displayBoard(board, cursor);

    std::cin >> input;

    // quit the game
    if ('q' == input) {
      break;
    }

    // inser value to the board
    if ('i' == input) {
      std::cout << "Enter a value(1-9) to insert: ";
      std::cin >> value;

      // Check if the input is valid (an int)
      /*if (!(std::cin >> value)) {
          std::cout << "Invalid value! Enter a number between 1 and 9."
                   << std::endl;
         std::cin.clear();             // clear the error
         std::cin.ignore(10000, '\n'); // Discard invalid input
         std::cin.get();
         continue;
       }*/

      // validate range
      if (value < 1 || value > 9) {
        std::cout << "Invalid value! Enter a number between 1 and 9."
                  << std::endl;
        std::cin.ignore();
        std::cin.get();
        continue;
      }

      // Validate placement
      if (game.isValidPlacement(board, cursor[0], cursor[1], value)) {
        game.insertValue(board, cursor[0], cursor[1], value);
      } else {
        std::cout << "Invalid placement! Try again." << std::endl;
        std::cin.ignore();
        std::cin.get();
      }
    }

    game.moveCursor(cursor, input);
  }

  return 0;
}

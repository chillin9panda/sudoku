#include "sudoku.h"
#include <iostream>

int main() {
  // game object
  sudoku game;

  // easy mode board
  int easy[9][9] = {
      {9, 4, 6, 3, 7, 1, 5, 0, 0}, {0, 7, 2, 9, 5, 0, 4, 6, 1},
      {8, 0, 5, 0, 6, 0, 3, 9, 7}, {0, 0, 0, 0, 1, 5, 0, 0, 0},
      {0, 0, 0, 0, 0, 2, 8, 1, 4}, {1, 0, 8, 4, 0, 0, 9, 0, 6},
      {4, 0, 0, 7, 0, 6, 0, 8, 0}, {0, 6, 9, 0, 0, 0, 0, 0, 0},
      {7, 8, 0, 5, 0, 0, 0, 3, 2},
  };

  // medium difficulty board
  int medium[9][9] = {
      {0, 0, 2, 0, 7, 1, 0, 6, 0}, {0, 3, 0, 0, 0, 8, 0, 7, 9},
      {4, 7, 6, 9, 0, 2, 8, 0, 0}, {0, 6, 9, 8, 0, 0, 5, 4, 2},
      {2, 0, 0, 6, 0, 5, 3, 8, 0}, {0, 0, 8, 7, 2, 4, 0, 0, 6},
      {1, 0, 7, 3, 0, 0, 6, 5, 4}, {6, 4, 3, 0, 0, 7, 0, 0, 0},
      {0, 9, 0, 0, 0, 0, 0, 3, 0},
  };

  // hard difficulty board
  int hard[9][9] = {
      {0, 3, 0, 8, 2, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {8, 0, 0, 5, 7, 0, 0, 1, 0}, {7, 0, 0, 2, 0, 0, 0, 0, 9},
      {0, 1, 0, 9, 8, 0, 0, 3, 0}, {6, 0, 0, 0, 0, 0, 0, 8, 4},
      {5, 9, 0, 0, 0, 0, 6, 0, 0}, {0, 0, 2, 0, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 7, 0, 0},
  };

  // board
  int board[9][9];

  game.difficultySwitch(hard, board); // load selected difficulty

  // Cursor starting position
  int cursor[2] = {0, 0};

  char input;
  int value;
  bool isEditable[9][9];
  int attempts = 0;
  const int maxAttempts = 3;

  // set cells as editable/changable only if value is 0 at the start of the game
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      isEditable[row][col] = (0 == board[row][col]);
    }
  }

  // Main Game loop
  while (true) {
    system("clear"); // use "cls" for windows

    std::cout << " Use w, a, s, d to move\n"
              << " i to insert value\n"
              << " q to quit\n"
              << std::endl;

    game.displayBoard(board, cursor);

    std::cout << "Choice: ";
    std::cin >> input;

    // quit the game
    if ('q' == input) {
      break;
    }

    // inser value to the board based on the cursor's placement
    if ('i' == input) {
      // Check if cell is editable
      if (!isEditable[cursor[0]][cursor[1]]) {
        std::cout << "Cannot Modify this cell!" << std::endl;
        std::cin.ignore();
        std::cin.get();
        continue;
      }

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

      // validate range of the value recieved
      if (value < 1 || value > 9) {
        std::cout << "\nInvalid value! Enter a number between 1 and 9."
                  << std::endl;
        std::cin.ignore();
        std::cin.get();
        continue;
      }

      // Validate placement and increament invalid attempts
      if (game.isValidPlacement(board, cursor[0], cursor[1], value)) {
        game.insertValue(board, cursor[0], cursor[1], value);
      } else {
        attempts++;
        std::cout << "\nWrong placement! Try again." << std::endl;
        std::cin.ignore();
        std::cin.get();
      }

      // Check winning Condition
      if (game.isWon(board)) {
        system("clear"); // Clear screen
        std::cout << "Congratulations, You've won the game!" << std::endl;
        break;
      }

      // CheckLosing Condition
      if (attempts == maxAttempts) {
        system("clear");
        std::cout << "GAME OVER!" << std::endl;
        system("pause"); // pause the screen until a key is pressed
        break;
      }
    }

    game.moveCursor(cursor, input);
  }

  return 0;
}

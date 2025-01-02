#include "score.h"
#include "sudoku.h"

int main() {
  // game objects
  sudoku game;
  score scoredPoints;
  ;

  // board
  int board[9][9] = {0};

  // load board with selected difficulty
  game.difficultySwitch(board);

  // Cursor starting position
  int cursor[2] = {0, 0};

  // Variable decalrations
  char input;
  int value;
  bool isEditable[9][9];
  int attempts = 0;
  const int maxAttempts = 3;
  double points = 0;

  // File to store high sccores
  const std::string highScores = "highscores.txt";
  scoredPoints.loadScoresFromFile(highScores);

  // set cells as editable/changable only if value is 0 at the start of the game
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      isEditable[row][col] = (0 == board[row][col]);
    }
  }

  game.startTimer();

  // Main Game loop
  while (true) {
    system("clear"); // use "cls" for windows
    std::cout << " Use w, a, s, d to move\n"
              << " i to insert value\n"
              << " q to quit\n"
              << std::endl;

    std::cout << "Points: " << points << std::endl;

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
        points = game.calculateScore(game.getDifficulty());
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
        game.stopTimer();
        system("pause");
        break;
      }

      // CheckLosing Condition
      if (attempts == maxAttempts) {
        system("clear");
        std::cout << "GAME OVER!" << std::endl;
        game.stopTimer();
        std::cin.get();
        break;
      }
    }

    game.moveCursor(cursor, input);
  }

  return 0;
}

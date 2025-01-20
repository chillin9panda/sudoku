#include "group.h"
#include "score.h"
#include "sudoku.h"

int main() {
  // game objects
  sudoku game;
  score scoredPoints;

  // board
  int board[9][9] = {0};

  // Cursor starting position
  int cursor[2] = {0, 0};

  // Variable decalrations
  char input;
  int value;
  bool isEditable[9][9];
  int attempts = 0;
  const int maxAttempts = 3;
  double points = 0;
  std::string name;
  char menuChoice;

  // File to store high sccores
  const std::string highScores = "highscores.txt";

  // load high score file
  scoredPoints.loadScoresFromFile(highScores);

  // set cells as editable/changable only if value is 0 at the start of the game
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      isEditable[row][col] = (0 == board[row][col]);
    }
  }

  system(CLEAR);
  do {
    std::cout << "\tSUDOKU SOLVER" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "1. New Game\n"
              << "2. High Scores\n"
              << "3. Quit" << std::endl;
    std::cout << "0. Group Members" << std::endl;
    std::cout << "Choice: ";
    std::cin >> menuChoice;

    switch (menuChoice) {
    case '1': {
      system(CLEAR);
      // load board with selected difficulty
      game.difficultySwitch(board);

      // Reset every thing after selecting difficulty/ starting a new game
      attempts = 0;
      points = game.resetTotalPoints();
      cursor[0] = 0;
      cursor[1] = 0;

      // Start timer
      game.startTimer();

      // Main Game loop
      while (true) {
        system("clear"); // use "cls" for windows
        std::cout << " Use w, a, s, d to move\n"
                  << " i to insert value\n"
                  << " q to quit\n"
                  << std::endl;

        std::cout << "Mistakes: " << attempts << " / " << maxAttempts
                  << std::endl;
        std::cout << "Points: " << points << "\n" << std::endl;

        game.displayBoard(board, cursor);

        std::cout << "Choice: ";
        std::cin >> input;

        // quit the game
        if ('q' == input) {
          system(CLEAR);
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
            system(CLEAR); // Clear screen
            std::cout << "Congratulations, You've won the game!" << std::endl;
            game.stopTimer();

            // check if the score is a new high score and save if so
            scoredPoints.insertHighScore(points, highScores);

            break;
          }

          // CheckLosing Condition
          if (attempts == maxAttempts) {
            system(CLEAR);
            std::cout << "GAME OVER!" << std::endl;
            game.stopTimer();
            std::cin.get();
            break;
          }
        }

        game.moveCursor(cursor, input);
      }

      break;
    }

    case '2': {
      system(CLEAR);
      // show high scores
      scoredPoints.viewHighscores();
      break;
    }
    case '3': {
      system(CLEAR);
      std::cout << "Exiting..." << std::endl;
      break;
    }
    case '0': {
      system(CLEAR);
      group groupMembers;
      groupMembers.groupMembers();
      break;
    }
    default: {
      std::cout << "Ivalid Choice!" << std::endl;
    }
    }

  } while ('3' != menuChoice);

  return 0;
}

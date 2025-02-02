#include "sudoku.h"

// show board as 9x9 on console and cursor starts at specified position in
// main.cpp
void sudoku::displayBoard(int board[9][9], int cursor[2]) {
  for (int row = 0; row < 9; row++) {            //  row
    for (int column = 0; column < 9; column++) { // column
      if (row == cursor[0] && column == cursor[1]) {
        std::cout << "[" << board[row][column] << "]"
                  << "   ";
      } else {
        std::cout << board[row][column] << "   ";
      }
    }
    std::cout << "\n" << std::endl;
  }
}

// insert/change value at the position of the cursor
void sudoku::insertValue(int board[9][9], int row, int column, int value) {
  board[row][column] = value;
}

// Move cursor arround the board
void sudoku::moveCursor(int cursor[2], char input) {
  if ('w' == input && cursor[0] > 0) // Move up
    cursor[0]--;
  if ('s' == input && cursor[0] < 8) // Move Down
    cursor[0]++;
  if ('a' == input && cursor[1] > 0) // Move left
    cursor[1]--;
  if ('d' == input && cursor[1] < 8) // Move Right
    cursor[1]++;
}

// Searching Algorithms
// vertical search for the inserted value
bool sudoku::verticalLinearSearch(int board[9][9], int col, int value,
                                  int skipRow) {
  for (int row = 0; row < 9; row++) {
    if (row == skipRow || 0 == value) {
      continue;
    }

    if (value == board[row][col]) {
      return true; // Found
    }
  }

  return false; // Not fouund
}

// Horizontal value for the inserted value
bool sudoku::horizontalLinearSearch(int board[9][9], int row, int value,
                                    int skipCol) {
  for (int col = 0; col < 9; col++) {
    if (col == skipCol || 0 == value) {
      continue;
    }

    if (value == board[row][col]) {
      return true; // Found
    }
  }

  return false; // Not found
}

// Search within the grid of 3x3
bool sudoku::gridSearch(int board[9][9], int startRow, int startCol, int value,
                        int skipRow, int skipCol) {

  int currentRow, currentCol;

  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      currentRow = startRow + row;
      currentCol = startCol + col;

      if ((currentRow == skipRow && currentCol == skipCol) || 0 == value) {
        continue;
      }

      if (value == board[currentRow][currentCol]) {
        return true; // Found
      }
    }
  }
  return false; // Not found
}

// check placememnt with the search Algorithms
bool sudoku::isValidPlacement(int board[9][9], int row, int col, int value) {
  // search starting points
  int startRow = row - row % 3; // Top lefy row of the grid
  int startCol = col - col % 3; // Top left column of the grid

  // Vallidation through the board
  return !horizontalLinearSearch(board, row, value, col) &&
         !verticalLinearSearch(board, col, value, row) &&
         !gridSearch(board, startRow, startCol, value, row, col);
}

// Checks if the game is won
bool sudoku::isWon(int board[9][9]) {
  // Check rows and column for completeness
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (0 == board[row][col]) {
        return false;
      }
    }
  }

  // If all cells are filled and no 0 is left
  return true;
}

// validation for board generation
// only one way to fill the board and win the game
bool sudoku::isValid(int board[9][9], int row, int col, int num) {
  for (int i = 0; i < 9; i++) {
    if (board[row][i] == num || board[i][col] == num)
      return false;

    int boxRow = row - row % 3 + i / 3;
    int boxCol = col - col % 3 + i % 3;

    if (board[boxRow][boxCol] == num)
      return false;
  }
  return true;
}

// Auto generate board at the beggining of the game
// fully numbered board 9x9
bool sudoku::generateBoard(int board[9][9], int row = 0, int col = 0) {
  if (row == 9)
    return true;
  if (col == 9)
    return generateBoard(board, row + 1, 0);
  if (0 != board[row][col])
    return generateBoard(board, row, col + 1);

  for (int i = 1; i <= 9; i++) {
    if (isValid(board, row, col, i)) {
      board[row][col] = i;
      if (generateBoard(board, row, col + 1))
        return true;
      board[row][col] = 0;
    }
  }
  return false;
}

// remove values from cells based on the difficulty
void sudoku::removeNumbers(int board[9][9], int emptyCells) {
  srand(time(0)); // randomize removed numbers
  while (emptyCells > 0) {
    int row = rand() % 9;
    int col = rand() % 9;

    if (board[row][col] != 0) {
      board[row][col] = 0;
      emptyCells--;
    }
  }
}

// switch to selected difficulty board to main board
void sudoku::difficultySwitch(int board[9][9]) {
  system(CLEAR);

  char difficultyOption;

  std::cout << "Difficulty Options" << std::endl;
  std::cout << "1. Easy\n" << "2. Medium\n" << "3. Hard" << std::endl;
  std::cout << "Select difficulty: ";
  std::cin >> difficultyOption;

  // set difficulty
  difficulty = difficultyOption;

  memset(board, 0, sizeof(int) * 81); // Clear board

  // Generate a full board
  if (!generateBoard(board)) {
    std::cout << "Error generating sudoku board" << std::endl;
    return;
  }

  int emptyCells = 0;

  switch (difficultyOption) {
  case '1': { // easy
    emptyCells = 30;
    break;
  }
  case '2': { // medium
    emptyCells = 35;
    break;
  }
  case '3': { // hard
    emptyCells = 40;
    break;
  }
  default: {
    std::cout << "Invalid Option" << std::endl;
    return;
  }
  }

  // generate board with cells empitied based on selected difficulty
  removeNumbers(board, emptyCells);
}

// Game timer
// start timer
void sudoku::startTimer() {
  liveTimer = true;
  startTime = std::chrono::steady_clock::now();

  std::thread([this]() {
    while (liveTimer) {
      auto now = std::chrono::steady_clock::now();
      auto elapsedSeconds =
          std::chrono::duration_cast<std::chrono::duration<double>>(now -
                                                                    startTime);
      elapsedTime = elapsedSeconds.count();

      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  }).detach();
}

// stop timer
void sudoku::stopTimer() {
  liveTimer = false;
  endTime = std::chrono::steady_clock::now();
  auto elapsedSeconds =
      std::chrono::duration_cast<std::chrono::duration<double>>(endTime -
                                                                startTime);
  elapsedTime = elapsedSeconds.count();

  std::cout << "\rTime Elapsed: " << std::fixed << std::setprecision(2)
            << elapsedTime << " Seconds\n"
            << std::flush;
}

// points Scoring
// calculate score with time passed
double sudoku::calculateScore(char difficulty) {
  switch (difficulty) {
  case '1': {
    scoredPoint = points.easyModePoints(elapsedTime);
    break;
  }
  case '2': {
    scoredPoint = points.mediumModePoints(elapsedTime);
    break;
  }
  case '3': {
    scoredPoint = points.hardModePoints(elapsedTime);
    break;
  }
  default: {
    std::cout << "Invalid Option" << std::endl;
  }
  }

  // calculate total points
  totalPoints += scoredPoint;

  return totalPoints;
}

// setters and getters
char sudoku::getDifficulty() { return difficulty; }

// resetTotalPoints to zero when games reset
double sudoku::resetTotalPoints() {
  totalPoints = 0;
  return totalPoints;
}

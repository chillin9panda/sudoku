#include "score.h"

// Calculate points based on difficulty and time elapsed
// for easy mode
double score::easyModePoints(double timeElapsed) {
  scorePoint = 0;
  if (timeElapsed < fiveMin) {
    scorePoint = easyPoints;
  } else if (timeElapsed < tenMin) {
    scorePoint = easyPoints / 1.2;
  } else if (timeElapsed < fifteenMin) {
    scorePoint = easyPoints / 1.4;
  } else {
    scorePoint = easyPoints / 1.5;
  }

  return scorePoint;
}

// for Medium Mode
double score::mediumModePoints(double timeElapsed) {
  scorePoint = 0;
  if (timeElapsed < fiveMin) {
    scorePoint = mediumPoints;
  } else if (timeElapsed < tenMin) {
    scorePoint = mediumPoints / 1.2;
  } else if (timeElapsed < fifteenMin) {
    scorePoint = mediumPoints / 1.4;
  } else if (timeElapsed < twentyMin) {
    scorePoint = mediumPoints / 1.6;
  } else {
    scorePoint = mediumPoints / 1.7;
  }

  return scorePoint;
}

// fpr Hard Mode
double score::hardModePoints(double timeElapsed) {
  scorePoint = 0;
  if (timeElapsed < fiveMin) {
    scorePoint = hardPoints;
  } else if (timeElapsed < tenMin) {
    scorePoint = hardPoints / 1.2;
  } else if (timeElapsed < fifteenMin) {
    scorePoint = hardPoints / 1.4;
  } else if (timeElapsed < twentyMin) {
    scorePoint = hardPoints / 1.6;
  } else if (timeElapsed < thirtyMin) {
    scorePoint = hardPoints / 2.0;
  } else {
    scorePoint = hardPoints / 2.2;
  }

  return scorePoint;
}

// high scores with linked list
// Clear current highScore list before loading
void score::clearHighScore() {
  while (head) {
    highScores *temp = head;
    head = head->nxt;
    delete temp;
  }
  head = NULL;
}

// load highscore file to linked list
void score::loadScoresFromFile(const std::string &highScoresFile) {
  clearHighScore();

  std::ifstream file(highScoresFile);

  // if file doesnt open
  if (!file.is_open()) {
    std::cout << "Error: Could not open file " << highScoresFile << std::endl;
    return;
  }

  std::string line;

  // load the scores to the linked list
  while (std::getline(file, line)) {
    std::istringstream ss(line);
    int rank;
    std::string name;
    double score;
    if (ss >> rank >> name >> score) {
      highScores *scoresNode = new highScores{rank, name, score, NULL};
      if (!head) {
        head = scoresNode;
      } else {
        highScores *temp = head;
        while (temp->nxt) {
          temp = temp->nxt;
        }
        temp->nxt = scoresNode;
      }
    }
  }

  // close file after loading to linked list
  file.close();
}

// insert new high score to the linked list
void score::insertHighScore(double score, const std::string &highScoresFile) {
  // if head of list is NULL or if score is highscore
  if (NULL == head || score > head->score) {
    std::string name;
    std::cout << "\nNew High Score!! You scored " << score << " points."
              << std::endl;
    std::cout << "Enter your name: ";
    std::cin >> name;

    highScores *scoresNode = new highScores{0, name, score, NULL};
    // Insert in sorted order
    if (!head || score > head->score) {
      scoresNode->nxt = head;
      head = scoresNode;
    } else { // if scored points is greater than the highscores in the list
      highScores *temp = head;
      while (temp->nxt && temp->nxt->score >= score) {
        temp = temp->nxt;
      }
      scoresNode->nxt = temp->nxt;
      temp->nxt = scoresNode;
    }

    // Keep only top 5 scores
    highScores *temp = head;
    int count = 1;
    while (temp && temp->nxt) {
      if (++count > maxHighScores) {
        delete temp->nxt;
        temp->nxt = NULL;
        break;
      }
      temp = temp->nxt;
    }

    // Update Rankings
    temp = head;
    int rank = 1;
    while (temp) {
      temp->rankNumber = rank++;
      temp = temp->nxt;
    }

    // Save the updated linked list to file
    saveScoreToFile(highScoresFile);
  }
}

// save the highscore to file
void score::saveScoreToFile(const std::string &highScoresFile) {
  std::ofstream file(highScoresFile); // open file

  if (!file.is_open()) {
    std::cout << "Could not open file " << highScoresFile << std::endl;
    return;
  }

  highScores *temp = head;

  // insert score to file
  while (temp) {
    file << std::fixed << std::setprecision(2) << temp->rankNumber << " "
         << temp->name << " " << temp->score << std::endl;
    temp = temp->nxt;
  }

  file.close(); // close file
}

// show all highscores
void score::viewHighscores() {
  // If thre is no score saved
  if (!head) {
    std::cout << "No high scores recorded yet." << std::endl;
    return;
  }

  std::cout << "\tHigh Scores" << std::endl;
  std::cout << "_______________________________" << std::endl;
  std::cout << "Rank\tName\tScores" << std::endl;
  std::cout << "_______________________________" << std::endl;

  highScores *temp = head;

  // List high scores
  while (temp) {
    std::cout << temp->rankNumber << "\t" << temp->name << "\t" << temp->score
              << std::endl;
    temp = temp->nxt;
  }
  std::cout << "_______________________________" << std::endl;
}

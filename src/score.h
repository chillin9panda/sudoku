#ifndef SCORE_H
#define SCORE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// Linked list to record top 5 highScores
struct highScores {
  int rankNumber;
  std::string name;
  double score;
  highScores *nxt;
};

class score {
private:
  // store points
  double scorePoint;

  // Points based on difficulty
  const int easyPoints = 100;
  const int mediumPoints = 200;
  const int hardPoints = 300;

  // Time in seconds
  const int fiveMin = 5 * 60;    // five minutes
  const int tenMin = 10 * 60;    // ten minutes
  const int fifteenMin = 5 * 60; // fifteen minutes
  const int twentyMin = 20 * 60; // twenty minutes
  const int thirtyMin = 30 * 60; // thirty Minutes
                                 //
  // Linked list
  highScores *head = NULL;

  const int maxHighScores =
      5; // maximum number of highscores that can be stored
public:
  double easyModePoints(double timeElapsed);
  double mediumModePoints(double timeElapsed);
  double hardModePoints(double timeElapsed);
  void loadScoresFromFile(const std::string &highScoresFile);
  void insertHighScore(double score, const std::string &highScoresFile);
  void saveScoreToFile(const std::string &highScoresFile);
  void viewHighscores();
};

#endif

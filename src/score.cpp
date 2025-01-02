#include "score.h"
#include <fstream>
#include <sstream>

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
void score::loadScoresFromFile(const std::string &highScoresFile) {
  std::ifstream file(highScoresFile);
  if (!file.is_open())
    return;

  std::string line;

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
  file.close();
}

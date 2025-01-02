#include "score.h"

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

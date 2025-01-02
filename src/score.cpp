#include "score.h"

int score::easyModePoints(double timeElapsed) {
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

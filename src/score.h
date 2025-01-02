#ifndef SCORE_H
#define SCORE_H

class score {
private:
  // store points
  double scorePoint;

  // Points based on difficulty
  const int easyPoints = 100;
  const int mediumPoints = 200;
  const int hardPoints = 300;

  // Time in seconds
  const int fiveMin = 300;    // five minutes
  const int tenMin = 600;     // ten minutes
  const int fifteenMin = 900; // fifteen minutes
  const int twentyMin = 1200; // twenty minutes

public:
  int easyModePoints(double timeElapsed);
};

#endif

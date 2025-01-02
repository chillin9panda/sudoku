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
  const int fiveMin = 5 * 60;    // five minutes
  const int tenMin = 10 * 60;    // ten minutes
  const int fifteenMin = 5 * 60; // fifteen minutes
  const int twentyMin = 20 * 60; // twenty minutes
  const int thirtyMin = 30 * 60; // thirty Minutes

public:
  double easyModePoints(double timeElapsed);
  double mediumModePoints(double timeElapsed);
  double hardModePoints(double timeElapsed);
};

#endif


#include <gtest/gtest.h>

#include <vector>

// ======================================================================
// bowlingScore
//
// (normally one would want to separate the implemenation on of the
// function / class from its tests, but to start its easiest to have it
// all together.

int bowlingScore(const std::vector<int>& rolls)
{
  int score = 0;
  for (int frame = 0; frame < 10; frame++) {
    int frame_start = 2 * frame;
    int frame_score = rolls[frame_start] + rolls[frame_start + 1];
    if (frame_score == 10) { // spare
      score += frame_score + rolls[frame_start + 2];
    } else {
      score += frame_score;
    }
  }
  return score;
}

// ======================================================================
// Tests

TEST(Bowling, AllZeros)
{
  std::vector<int> rolls = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  };
  EXPECT_EQ(bowlingScore(rolls), 0);
}

TEST(Bowling, RegularGame)
{
  std::vector<int> rolls = {
    0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6,
  };
  EXPECT_EQ(bowlingScore(rolls), 14);
}

TEST(Bowling, Spare)
{
  std::vector<int> rolls = {
    0, 0, 2, 3, 4, 6, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6,
  };
  EXPECT_EQ(bowlingScore(rolls), 5 + 4 + 6 + 3 + 3 + 4 + 3 + 6);
}

#ifndef GOAL_FINDER_H
#define GOAL_FINDER_H

#include "Filter.h"

class GoalFinder
{
private:
  Filter m_averager;

  float m_last;
  float m_curr;

public:
  GoalFinder();
  void Process(float value);
  bool FoundGoal();
  bool FoundGoalFront();
};

#endif // GOAL_FINDER_H

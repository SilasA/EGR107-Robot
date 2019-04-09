#ifndef GOAL_FINDER_H
#define GOAL_FINDER_H

#include "Filter.h"

class GoalFinder
{
private:
  Filter m_averager;

public:
  GoalFinder();
  void Process(float value);
  bool FoundGoal();
};

#endif // GOAL_FINDER_H

#include "GoalFinder.h"

GoalFinder::GoalFinder() :
  m_averager(10)
{
}

void GoalFinder::Process(float value)
{
  m_averager.Add(value);
}

bool GoalFinder::FoundGoal()
{
  float *data;
  int size;
  m_averager.GetDataInOrder(data, &size);

  if (size < 5)
  {
    return false;
  }
  else
  {
    return data[0] - data[1] > 10;
  }
}

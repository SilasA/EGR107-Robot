#include "GoalFinder.h"
#include "Arduino.h"

GoalFinder::GoalFinder() :
  m_averager(6)
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
    Serial.print(data[0]);
    Serial.print("\t");
    Serial.println(data[1]);
    return data[0] - data[1] > 15;
  }
}

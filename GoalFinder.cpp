#include "GoalFinder.h"
#include "Arduino.h"
#include "Command.h"
#include "Constants.h"

GoalFinder::GoalFinder() :
  m_averager(4)
{
  m_last = 0;
  m_last = 0;
}

void GoalFinder::Process(float value)
{
  //m_averager.Add(value);
  m_last = m_curr;
  m_curr = value;
  
}

bool GoalFinder::FoundGoal()
{
  //float *data;
  //int size;
  //m_averager.GetDataInOrder(data, &size);

  /*if (size < 3)
  {
    return false;
  }
  else
  {
    Serial.print(data[0]);
    Serial.print("\t");
    Serial.println(data[1]);
    return data[0] - data[1] > 15;
  }*/
  
  if (m_last == 0 || m_curr == 0)
    return false;

  Serial.print("GAP: ");
  Serial.println(m_curr - m_last);
  return m_curr - m_last > 15;
}

bool GoalFinder::FoundGoalFront()
{
  return Command::sensors.GetFrontFilter() - Command::sensors.GetFrontTopFilter() > GOAL_DIFF &&
    Command::sensors.GetFrontTopFilter() < 25;
} 

#ifndef DRIVE_H
#define DRIVE_H

#include "Command.h"
#include "GoalFinder.h"

class Drive : public Command
{
private:
  bool m_isDistance;
  float m_value;
  float m_ramp;
  float m_duration;

  unsigned long m_startTime;
  float m_currentValue;

  GoalFinder m_goalFinder;

  bool m_isObstacle = false;
  bool m_frontWall = false;
  bool m_frontGoal = false;

public:
  Drive(float value, float ramp, float duration, bool isDistance = false);
  void Init();
  void Run();
  bool Finished();
  void End();
};

#endif // DRIVE_H

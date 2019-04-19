#include "Drive.h"
#include "Turn.h"
#include "FollowWall.h"
#include "SweepForwards.h"
#include "SweepBackwards.h"
#include "SweepStop.h"

Drive::Drive(float value, float ramp, float duration, bool isDistance)
{
  m_value = duration < 0 ? -value : value;
  m_isDistance = isDistance;
  m_duration = inch_to_count(duration);

  if (ramp == -1) ramp = m_value;
  else m_ramp = ramp;

  Command::commandsQueued++;
}

void Drive::Init()
{
  m_currentValue = 0;
  m_startTime = millis();
  Serial.println(m_startTime);
  Command::driveTrain.ZeroEnc();
}

void Drive::Run()
{
  //Command::driveTrain.Drive(m_value / 255.0, m_value / 255.0);
  Command::driveTrain.ArcadeDrive(m_value / 255.0, 0);

  m_frontGoal = m_goalFinder.FoundGoalFront();

  m_isObstacle = Command::driveTrain.IsStalled() || Command::sensors.AtWall();
  //m_frontWall = Command::sensors.AtWall();
}

bool Drive::Finished()
{
  if (m_isDistance)
  {
    if (m_duration < 0)
      return m_duration - Command::driveTrain.GetLeftDistance() > 0 ||
        m_duration - Command::driveTrain.GetRightDistance() > 0 ||
        (m_startTime + 500 <= millis() && m_isObstacle) || (m_frontWall && m_duration > 0);
    else 
      return m_duration - Command::driveTrain.GetLeftDistance() < 0 ||
        m_duration - Command::driveTrain.GetRightDistance() < 0 ||
        (m_startTime + 500 <= millis() && m_isObstacle) || (m_frontWall && m_duration > 0) ||
        m_frontGoal;
  }
  else
    return m_startTime + m_duration <= millis();
}

void Drive::End()
{
  if (m_isObstacle)
  {
    Serial.println("Obstacle");
    //Command::Push(new SweepStop());
    Command::Push(new Drive(100, -1, (m_duration > 0 ? -7 : 7), true));
    //Command::Push(new SweepForwards());
    Command::Push(new Turn(950));
    //Command::Push(new Drive(120, -1, 50, true));
  }
  else if (m_frontWall)
  {
    Serial.println("Wall");
    Command::Push(new Drive(150, -1, -5, true));
    Command::Push(new Turn(1500));
    Command::Push(new FollowWall(12, 60));
  }
  else if (m_frontGoal)
  {
    Serial.print("Goal");
    Command::Push(new SweepBackwards());
    Command::Push(new Drive(100, -1, -10, true));
    Command::Push(new SweepForwards());
    //Command::Push(new Drive(100, -1, 50, true));
  }
  else 
  {
    Serial.println("None");
    Command::Push(new Turn(1150));
    //Command::Push(new Drive(120, -1, 50, true));
  }
  Command::commandsQueued--;
  //Command::driveTrain.Drive(0,0);
}   

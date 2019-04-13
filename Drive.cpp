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

  m_isObstacle = Command::driveTrain.IsStalled();
  m_frontWall = Command::sensors.AtWall();
}

bool Drive::Finished()
{
  if (m_isDistance)
    return abs(m_duration - Command::driveTrain.GetLeftDistance()) < 50 ||
      abs(m_duration - Command::driveTrain.GetRightDistance()) < 50 ||
      (m_startTime + 1000 <= millis() && m_isObstacle) || (m_frontWall && m_duration > 0) ;
  else
    return m_startTime + m_duration <= millis();
}

void Drive::End()
{
  if (m_isObstacle)
  {
    Serial.println("Obstacle");
    Command::Push(new SweepStop());
    Command::Push(new Drive(120, -1, -9, true));
    Command::Push(new SweepForwards());
    Command::Push(new Turn(0));
    Command::Push(new Drive(120, -1, 30, true));
  }
  else if (m_frontWall)
  {
    Serial.println("Wall");
    Command::Push(new Drive(100, -1, -5, true));
    Command::Push(new Turn(90));
    Command::Push(new FollowWall(12, 60));
  }
  else
  {
    Serial.println("None");
    Command::Push(new Turn(60));
    Command::Push(new Drive(120, -1, 30, true));
  }
  //Command::driveTrain.Drive(0,0);
}   

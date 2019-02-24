#include "Turn.h"

Turn::Turn(float speed, long duration)
{
  m_speed = speed;
  m_duration = duration;
}

void Turn::Init()
{
  m_startTime = millis();
}

void Turn::Run()
{
  Command::driveTrain.Drive(-m_speed / 2, m_speed / 2);
}

bool Turn::Finished()
{
  return m_startTime + m_duration <= millis();
}

void Turn::End()
{
  Command::driveTrain.Drive(0, 0);
}

#include "Turn.h"

Turn::Turn(int dist)
{
  m_displacement = dist;
  m_drive = &Command::driveTrain;
}

void Turn::Init()
{
  Serial.println("Turning");
}

void Turn::Run()
{
  Command::driveTrain.Drive(-.4, .4);

  m_isObstacle = Command::driveTrain.IsStalled();
}

bool Turn::Finished()
{
  return abs(m_displacement - m_drive->GetLeftDistance()) < 5 ||
      abs(-m_displacement - m_drive->GetRightDistance()) < 5 || m_isObstacle;
}

void Turn::End()
{
  Command::driveTrain.Drive(0, 0);
}

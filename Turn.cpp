#include "Turn.h"

Turn::Turn(int dist)
{
  m_displacement = dist;
  m_drive = &Command::driveTrain;
}

void Turn::Init()
{
  m_startTime = millis();
  Serial.println("Turning");
}

void Turn::Run()
{
  Command::driveTrain.Drive(-.2, .2);
}

bool Turn::Finished()
{
  return abs(m_displacement - m_drive->GetLeftDistance()) < 10 ||
      abs(-m_displacement - m_drive->GetRightDistance()) < 10;
}

void Turn::End()
{
  Command::driveTrain.Drive(0, 0);
}

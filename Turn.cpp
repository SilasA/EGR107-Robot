#include "Turn.h"

Turn::Turn(int dist)
{
  m_displacement = dist;
  m_drive = &Command::driveTrain;
}

void Turn::Init()
{
  Serial.println("Turning");
  m_startTime = millis();

  Command::driveTrain.ZeroEnc();
}

void Turn::Run()
{
  if (m_displacement < 0)
    Command::driveTrain.Drive(.5, -.4);
  else
    Command::driveTrain.Drive(-.40, .4);
  //Command::driveTrain.ArcadeDrive(0, m_displacement > 0 ? .35 : -.35);

  m_isObstacle = Command::driveTrain.IsStalled();
}

bool Turn::Finished()
{
  Serial.print(abs(m_displacement + m_drive->GetLeftDistance()));
  Serial.print("\t");
  Serial.print(abs(m_displacement - m_drive->GetRightDistance()));
  Serial.print("\t");
    return abs(m_displacement + m_drive->GetLeftDistance()) < 50 ||
     (m_startTime + 500 <= millis() && m_isObstacle) ||
      abs(m_displacement - m_drive->GetRightDistance()) < 50;
}

void Turn::End()
{
  Command::driveTrain.Drive(0, 0);
}

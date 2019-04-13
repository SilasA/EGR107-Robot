#include "Turn.h"

Turn::Turn(int dist)
{
  m_displacement = deg_to_count(dist);
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
    Command::driveTrain.Drive(0, .75);
  else
    Command::driveTrain.Drive(.75, 0);
  //Command::driveTrain.ArcadeDrive(0, m_displacement > 0 ? .35 : -.35);

  m_isObstacle = Command::driveTrain.IsStalled();
}

bool Turn::Finished()
{
  int32_t error;
  if (m_displacement < 0){
    error = abs(m_displacement) - m_drive->GetRightDistance();
    //Serial.print("R Error: ");
    //Serial.println(error);
  }
  else 
  {
    error = abs(m_displacement) - m_drive->GetLeftDistance();
    Serial.print("L Error: ");
    Serial.println(error);
  }
    
  return error < 0 || (m_startTime + 1000 <= millis() && m_isObstacle);
}

void Turn::End()
{
  Command::driveTrain.Drive(0, 0);
}

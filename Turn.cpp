#include "Turn.h"
#include "Drive.h"

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
    Command::driveTrain.Drive(0, .4);
  else
    Command::driveTrain.Drive(.4, 0);
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
    //Serial.print("L Error: ");
    //Serial.println(error);
  }
    
  return m_startTime + 950 <= millis(); //error < 0 || (m_startTime + 1000 <= millis() && m_isObstacle);
}

void Turn::End()
{
  if (m_isObstacle)
  {
    Command::Push(new Drive(1000, -1, -10, true));
    Command::Push(new Drive(100, -1, 25, true));
  }
  //Command::driveTrain.Drive(0, 0);
}

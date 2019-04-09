#include "Drive.h"
#include "Turn.h"

Drive::Drive(float value, float ramp, unsigned long duration, bool isDistance)
{
  m_value = value;
  m_isDistance = isDistance;
  m_duration = duration;

  if (ramp == -1) ramp = m_value;
  m_ramp = ramp;
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
  Command::driveTrain.ArcadeDrive(m_value, 0);

  m_isObstacle = Command::driveTrain.IsStalled();
}

bool Drive::Finished()
{
  if (m_isDistance)
    return Command::driveTrain.GetLeftDistance() == m_duration ||
      Command::driveTrain.GetRightDistance() == m_duration ||
      (m_startTime + 500 <= millis() && m_isObstacle);
  else
    return m_startTime + m_duration <= millis();
}

void Drive::End()
{
  Command::driveTrain.Drive(0,0);
}

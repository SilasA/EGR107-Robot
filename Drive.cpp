#include "Drive.h"

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
}

void Drive::Run()
{
  m_currentValue += m_startTime + m_duration - 500 <= millis() ? m_ramp : -m_ramp;
  if (m_currentValue > m_value)
    m_currentValue = m_value;
  else if (m_currentValue < 0)
    m_currentValue = 0;
  Command::driveTrain.Drive(m_currentValue, m_currentValue);
}

bool Drive::Finished()
{
  return m_startTime + m_duration <= millis();
}

void Drive::End()
{
  Command::driveTrain.Drive(0, 0);
}

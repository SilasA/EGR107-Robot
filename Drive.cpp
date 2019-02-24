#include "Drive.h"
#include "DriveTrain.h"

Drive::Drive(float value, float ramp, bool isDistance)
{
  m_value = value;
  m_isDistance = isDistance;

  if (ramp == -1) ramp = m_value;
  m_ramp = ramp;
}

void Drive::Init()
{
  m_currentValue = 0;
}

void Drive::Run()
{
  m_currentValue += m_ramp;
  if (m_currentValue > m_value)
    m_currentValue = m_value;
}

bool Drive::Finished()
{
  return 
}

void Drive::End()
{

}

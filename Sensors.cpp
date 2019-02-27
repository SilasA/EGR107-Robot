#include "Sensors.h"

Sensors::Sensors(const char *name, int irLeft, int irRight,
                 int sonarTrig, int sonarEcho) :
                 m_left(irLeft), m_right(irRight), m_ballSonar(sonarTrig, sonarEcho)
{

}

float GetLeftDistance()
{
  return m_left.GetDistance();
}

float GetRightDistance()
{
  return m_right.GetDistance();
}

bool FoundBall()
{
  // Check if distance is certain range lower than normal
}

bool FoundBeacon()
{
  // Still unsure of how code works for this
}

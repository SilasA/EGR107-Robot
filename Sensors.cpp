#include "Sensors.h"

float get_average(float *array, int size)
{
    float avg;
    for (int i = 0; i < size; i++)
        avg += array[i];
    return avg / size;
}

Sensors::Sensors(const char *name, int irLeft, int irRight, int irFront, int irBeacon,
                 int sonarTrig, int sonarEcho) :
                 Subsystem(name), m_left(irLeft), m_right(irRight), m_front(irFront),
                 m_beaconLocator(irBeacon), m_ballSonar(sonarTrig, sonarEcho),
                 m_ballFilter(5), m_frontFilter(10), m_leftFilter(10), m_rightFilter(10)
{

}

float Sensors::GetLeft()
{
  m_leftFilter.Add(m_left.GetDistance());
  return m_left.GetDistance();
}

float Sensors::GetRight()
{
  m_rightFilter.Add(m_right.GetDistance());
  return m_right.GetDistance();
}

float Sensors::GetFront()
{
    m_frontFilter.Add(m_front.GetDistance());
    return m_right.GetDistance();
}

float Sensors::GetLeftFilter()
{
  m_leftFilter.Add(m_left.GetDistance());
  return m_leftFilter.GetAverage();
}

float Sensors::GetRightFilter()
{
  m_rightFilter.Add(m_right.GetDistance());
  return m_rightFilter.GetAverage();
}

float Sensors::GetFrontFilter()
{
    m_frontFilter.Add(m_front.GetDistance());
    return m_frontFilter.GetAverage();
}

bool Sensors::FoundBall()
{
  // Check if distance is certain range lower than normal
  long echoTime = m_ballSonar.ping_median(5);
  float dist = m_ballSonar.convert_in(echoTime);
  return dist < kBallDistance + .75 && dist > kBallDistance - .75;
}

bool Sensors::FoundBeacon()
{
  return GetBeaconLuminosity() >= kGoalLuminosity;
}

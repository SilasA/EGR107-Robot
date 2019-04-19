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
                 m_photocell(irBeacon), m_topGoalSonar(sonarTrig, sonarEcho),
                 m_topGoalFilter(5), m_frontFilter(5), m_leftFilter(5), m_rightFilter(5)
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

float Sensors::GetFrontTop()
{
  float d = m_topGoalSonar.ping_cm();
  if (d == 0.0) return 150;
  m_topGoalFilter.Add(d);
  return d;
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

float Sensors::GetFrontTopFilter()
{
  float d = m_topGoalSonar.ping_cm();
  if (d == 0.0) return 150;
  m_topGoalFilter.Add(d);
  return m_topGoalFilter.GetAverage();
}

bool Sensors::AtWall()
{
  return m_frontFilter.GetAverage() < 20 && m_topGoalFilter.GetAverage() < 20;
}

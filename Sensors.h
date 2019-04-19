#ifndef SENSORS_H
#define SENSORS_H

#include "Subsystem.h"
#include "NewPing.h"
#include "Filter.h"
#include "IR.h"
#include "Photocell.h"

class Sensors : public Subsystem
{
private:
  IR m_left;
  IR m_right;
  IR m_front;
  Photocell m_photocell;
  Filter m_leftFilter;
  Filter m_rightFilter;
  Filter m_frontFilter;

  NewPing m_topGoalSonar;
  Filter m_topGoalFilter;

  float get_average(float *array, int size);

public:
  // ~40 degrees 5.4" from floor ball width average 1.625"
  const float kNormalDistance = 7.05;
  const float kBallDistance = 7.05 - 2.0;
  const int kGoalLuminosity = -1;

  Sensors(const char *name, int irLeft, int irRight, int irFront, int irBeacon, int sonarTrig, int sonarEcho);

  float GetLeft();
  float GetRight();
  float GetFront();
  float GetFrontTop();
  float GetLeftFilter();
  float GetRightFilter();
  float GetFrontFilter();
  float GetFrontTopFilter();
  bool AtWall();
};

#endif // SENSORS_H

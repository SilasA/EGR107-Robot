#ifndef SENSORS_H
#define SENSORS_H

#include "Subsystem.h"
#include "NewPing.h"

class Sensors : public Subsystem
{
private:
  IR m_left;
  IR m_right;

  IR m_beaconLocator;

  NewPing m_ballSonar;

public:
  // ~40 degrees 5.4" from floor ball width average 1.625"
  const float kNormalDistance = 7.05;
  const float kBallDistance = 7.05 - 2.0;

  Sensors(const char *name, int irLeft, int irRight, int sonarTrig, int sonarEcho);

  // Implement filters
  float GetLeftDistance();
  float GetRightDistance();
  bool FoundBall();
  bool FoundBeacon();
};

#endif // SENSORS_H

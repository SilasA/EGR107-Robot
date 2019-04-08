#ifndef PHOTOCELL_H
#define PHOTOCELL_H

#include "Arduino.h"

//
class Photocell
{
private:
  int m_pin;

public:
  Photocell(int pin)
  {
    m_pin = pin;
  }

  int GetIntensity() { return 1023 - analogRead(m_pin); }
};

#endif // PHOTOCELL_H

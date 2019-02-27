#ifndef IR_H
#define IR_H

#include "Arduino.h"

// Class to interface with Sharp IR Sensor
class IR
{
private:
  int m_pin;

public:
  IR(int pin)
  {
    m_pin = pin;
  }

  float GetDistance() { return 6787 / (analogRead(m_pin) - 3) - 4; }
};

#endif // IR_H

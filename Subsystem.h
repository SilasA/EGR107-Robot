#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

#include "Arduino.h"
#include "Constants.h"

//
class Subsystem
{
private:
  const char *m_name;

public:
  Subsystem(const char *name)
  {
    m_name = name;
  }
  const char *GetName() { return m_name; }

  int32_t inch_to_count(float inches)
  {
    return inches / INCH_PER_REV * COUNTS_PER_REV;
  }

  int32_t deg_to_count(float deg)
  {
    return inch_to_count(deg * INCH_PER_DEG);
  }
};

#endif // SUBSYSTEM_H

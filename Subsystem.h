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
};

#endif // SUBSYSTEM_H

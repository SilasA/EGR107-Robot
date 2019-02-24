#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

//
class Subsystem
{
private:
  char *m_name;

public:
  Subsystem(char *name)
  {
    m_name = name;
  }
  char *GetName() { return m_name; }
};

#endif // SUBSYSTEM_H

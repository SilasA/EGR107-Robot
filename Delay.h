#ifndef DELAY_H
#define DELAY_H

#include "Command.h"

class Delay : public Command
{
private:
  unsigned long m_mil;
  unsigned long m_start;

public:
  Delay(unsigned long mil);
  void Init();
  void Run();
  bool Finished();
  void End();
};

#endif // DELAY_H

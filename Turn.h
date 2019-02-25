#ifndef TURN_H
#define TURN_H

#include "Command.h"

class Turn : public Command
{
private:
  float m_speed;

  long m_duration;
  unsigned long m_startTime;

public:
  Turn(float speed, long duration);

  void Init();
  void Run();
  bool Finished();
  void End();
};

#endif // TURN_H

#ifndef TURN_H
#define TURN_H

#include "Command.h"

class Turn : public Command
{
private:
  DriveTrain *m_drive;
  float m_displacement;

  bool m_isObstacle = false;

  long m_startTime;

public:
  Turn(long dist);

  void Init();
  void Run();
  bool Finished();
  void End();
};

#endif // TURN_H

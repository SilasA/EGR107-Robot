#ifndef TURN_H
#define TURN_H

#include "Command.h"

class Turn : public Command
{
private:
  DriveTrain *m_drive;
  float m_displacement;

  bool m_isObstacle = false;

public:
  Turn(int dist);

  void Init();
  void Run();
  bool Finished();
  void End();
};

#endif // TURN_H

#ifndef ARCADE_TURN_H
#define ARCADE_TURN_H

#include "Command.h"

class ArcadeTurn : public Command
{
private:
  float speed;

public:
  ArcadeTurn(float speed);
  void Init();
  void Run();
  bool Finished();
  void End();
};

#endif // ARCADE_TURN_H

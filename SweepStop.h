/*********************************************************************
 * Author(s):
 * Date:
 * Description:
 ********************************************************************/

#ifndef SWEEP_STOP_H
#define SWEEP_STOP_H

#include "Command.h"

// Turns the sweeper on intake
class SweepStop : public Command
{
public:
  SweepStop();
  void Init();
  void Run();
  bool Finished();
  void End();
};

#endif // SWEEP_STOP_H

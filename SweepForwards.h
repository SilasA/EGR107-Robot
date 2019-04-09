/*********************************************************************
 * Author(s):
 * Date:
 * Description:
 ********************************************************************/

#ifndef SWEEP_FORWARDS_H
#define SWEEP_FORWARDS_H

#include "Command.h"

// Turns the sweeper on intake
class SweepForwards : Command
{
public:
  SweepForwards();
  void Init();
  void Run();
  bool Finished();
  void End();
};

#endif // SWEEP_FORWARDS_H

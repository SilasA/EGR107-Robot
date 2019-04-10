/*********************************************************************
 * Author(s):
 * Date:
 * Description:
 ********************************************************************/

#ifndef SWEEP_BACKWARDS_H
#define SWEEP_BACKWARDS_H

#include "Command.h"

// Turns the sweeper on intake
class SweepBackwards : public Command
{
public:
  SweepBackwards();
  void Init();
  void Run();
  bool Finished();
  void End();
};

#endif // SWEEP_FORWARDS_H

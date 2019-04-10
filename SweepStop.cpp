#include "SweepStop.h"

SweepStop::SweepStop() : Command()
{
}

void SweepStop::Init()
{
  Command::driveTrain.Sweep(0);
}

void SweepStop::Run()
{
}

bool SweepStop::Finished()
{
  return true;
}

void SweepStop::End()
{
}

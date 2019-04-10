#include "SweepForwards.h"

SweepForwards::SweepForwards() : Command()
{
}

void SweepForwards::Init()
{
  Command::driveTrain.Sweep(.2);
}

void SweepForwards::Run()
{
}

bool SweepForwards::Finished()
{
  return true;
}

void SweepForwards::End()
{
}

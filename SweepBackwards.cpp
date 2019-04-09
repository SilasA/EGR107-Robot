#include "SweepBackwards.h"

SweepBackwards::SweepBackwards() : Command()
{
}

void SweepBackwards::Init()
{
  Command::driveTrain.Sweep(.2);
}

void SweepBackwards::Run()
{
}

bool SweepBackwards::Finished()
{
  return true;
}

void SweepBackwards::End()
{
}

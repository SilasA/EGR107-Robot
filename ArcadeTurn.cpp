#include "ArcadeTurn.h"

ArcadeTurn::ArcadeTurn(float speed)
{
  this->speed = speed;
}

void ArcadeTurn::Init()
{
}

void ArcadeTurn::Run()
{
  Command::driveTrain.ArcadeDrive(0, speed);
}

bool ArcadeTurn::Finished()
{
  return false;
}

void ArcadeTurn::End()
{
}

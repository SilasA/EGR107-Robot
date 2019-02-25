#include "DriveTriangle.h"
#include "Drive.h"
#include "Turn.h"

DriveTriangle::DriveTriangle()
{

}

void DriveTriangle::Init()
{
  Command::Push(new Drive(100, 5, 3000));
  Command::Push(new Turn(100, 1)); // Duration tbd
  Command::Push(new Drive(100, 5, 3000));
  Command::Push(new Turn(100, 1)); // Duration tbd
  Command::Push(new Drive(100, 5, 3000));
  Command::Push(new Turn(100, 1)); // Duration tbd
}

void DriveTriangle::Run()
{
  return;
}

bool DriveTriangle::Finished()
{
  return true; // Single iteration command
}

void DriveTriangle::End()
{

}

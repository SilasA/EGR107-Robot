#include "DriveTriangle.h"
#include "Drive.h"
#include "Turn.h"

DriveTriangle::DriveTriangle()
{

}

void DriveTriangle::Init()
{
  Command::Push(new Drive(150, 2, 5000));
  Command::Push(new Turn(250, 1000)); // Duration tbd
  Command::Push(new Drive(150, 2, 5000));
  Command::Push(new Turn(250, 1000)); // Duration tbd
  Command::Push(new Drive(150, 2, 5000));
  Command::Push(new Turn(250, 1000)); // Duration tbd
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

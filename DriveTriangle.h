#ifndef DRIVE_TRIANGLE_H
#define DRIVE_TRIANGLE_H

#include "Command.h"

// Drive an equilateral triangle
class DriveTriangle : public Command
{
private:

public:
  DriveTriangle();
  void Init();
  void Run();
  bool Finished();
  void End();
};

#endif // DRIVE_TRIANGLE_H

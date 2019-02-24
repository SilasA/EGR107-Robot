#include "DriveTrain.h"

void DriveTrain::set_direction(int hb1, int hb2, int direction)
{
  if (direction > 0)
  {
    digitalWrite(hb1, HIGH);
    digitalWrite(hb2, LOW);
  }
  else
  {
    digitalWrite(hb1, LOW);
    digitalWrite(hb2, HIGH);
  }
}

DriveTrain::DriveTrain(char *name,
  int lpin, int lhb1, int lhb2,
  int rpin, int rhb1, int rhb2)
{

}

void Drive(float left, float right)
{

}

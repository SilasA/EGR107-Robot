#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include "Subsystem.h"

//
class DriveTrain : public Subsystem
{
private:
  int m_lpin;
  int m_rpin;
  int m_lhb1;
  int m_lhb2;
  int m_rhb1;
  int m_rhb2;

  void set_direction(int hb1, int hb2, int direction);

public:
  DriveTrain(char *name,
    int lpin, int lhb1, int lhb2,
    int rpin, int rhb1, int rhb2);
  void Drive(float left, float right);
};

#endif // DRIVE_TRAIN_H

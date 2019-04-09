#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include "Subsystem.h"
#include "Encoder.h"
#include "Servo.h"

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

  Servo m_sweeper;

  Encoder m_leftEnc;
  Encoder m_rightEnc;

  float m_leftOutput;
  float m_rightOutput;

  int m_leftPosition;
  int m_rightPosition;

  void set_direction(int hb1, int hb2, float direction);
  //float max(float a, float b);

public:
  DriveTrain(const char *name, int lpin, int lhb1, int lhb2,
            int rpin, int rhb1, int rhb2,
            int leftEncA, int leftEncB,
            int rightEncA, int rightEncB,
            int sweeper);

   void Init();

  void Drive(float left, float right);
  void ArcadeDrive(float drive, float rotate);

  void Sweep(float speed);

  void ZeroEnc();

  int32_t GetLeftDistance();
  int32_t GetRightDistance();

  bool IsStalled();
};

#endif // DRIVE_TRAIN_H

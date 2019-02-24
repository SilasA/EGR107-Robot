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
  m_lpin = lpin;
  m_rpin = rpin;
  m_lhb1 = lhb1;
  m_lhb2 = lhb2;
  m_rhb1 = rhb1;
  m_rhb2 = rhb2;

  // Pin setup
}

void Drive(float left, float right)
{
  set_direction(m_lhb1, m_lhb2, left);
  set_direction(m_rhb1, m_rhb2, right);

  analogWrite(lpin, left * 128);
  analogWrite(rpin, right * 128);
}

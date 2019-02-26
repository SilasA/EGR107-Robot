#include "DriveTrain.h"

void DriveTrain::set_direction(int hb1, int hb2, int direction)
{
  if (direction > 0) // Forwards
  {
    digitalWrite(hb1, LOW);
    digitalWrite(hb2, HIGH);
  }
  else // Reverse
  {
    digitalWrite(hb1, HIGH);
    digitalWrite(hb2, LOW);
  }
}

DriveTrain::DriveTrain(const char *name,
  int lpin, int lhb1, int lhb2,
  int rpin, int rhb1, int rhb2) :
  Subsystem(name)
{
  m_lpin = lpin;
  m_rpin = rpin;
  m_lhb1 = lhb1;
  m_lhb2 = lhb2;
  m_rhb1 = rhb1;
  m_rhb2 = rhb2;

  // Pin setup
  pinMode(m_lpin, OUTPUT);
  pinMode(m_lhb1, OUTPUT);
  pinMode(m_lhb2, OUTPUT);
  pinMode(m_rpin, OUTPUT);
  pinMode(m_rhb1, OUTPUT);
  pinMode(m_rhb2, OUTPUT);
}

float DriveTrain::max(float a, float b)
{
  return a > b ? a : b;
}

void DriveTrain::Drive(float left, float right)
{
  set_direction(m_lhb1, m_lhb2, left);
  set_direction(m_rhb1, m_rhb2, right);

  analogWrite(m_lpin, left * 255);
  analogWrite(m_rpin, right * 255);
}

void DriveTrain::ArcadeDrive(float drive, float rotate)
{
  float loutput;
  float routput;

  if (drive > 0.0)
  {
    if (rotate > 0.0)
    {
      loutput = drive - rotate;
      routput = max(drive, rotate);
    }
    else
    {
      loutput = -max(-drive, rotate);
      routput = move + rotate;
    }
  }
  else
  {
    if (rotate > 0.0)
    {
      loutput = -max(-move, rotate);
      routput = move + rotate;
    }
    else
    {
      loutput = move - rotate;
      routput = -max(-move, -rotate);
    }
  }

  Drive(louput, routput);
}

int GetLeftDistance()
{
  // Maybe convert to units
  return m_leftEnc.read();
}

int GetRightDistance()
{
  // Maybe convert to units
  return m_rightEnc.read();
}

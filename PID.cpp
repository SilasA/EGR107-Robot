#include "PID.h"

PID::PID(float kp, float ki, float kd, float max, float min)
{
  m_kp = kp;
  m_ki = ki;
  m_kd = kd;
  m_maxOut = max;
  m_minOut = min;

  m_iAccum = 0;
  m_lastT = millis();
}

PID::PID(float kp, float ki, float kd) :
  PID(kp, ki, kd, 100, -100);
{
}

void PID::SetPID(float kp, float ki, float kd)
{
  m_kp = kp;
  m_ki = ki;
  m_kd = kd;
}

void PID::SetOutput(float max, float min)
{
  m_maxOut = max;
  m_minOut = min;
}

void PID::ResetIAccum()
{
  m_iAccum = 0;
}

float PID::Run(float input, float setpoint)
{
  float error = setpoint - input;
  unsigned long t = millis();
  unsigned long dt = t - m_lastT;
  m_lastT = t;

  // P
  float p = m_kp * error;

  // I
  m_iAccum += error * dt;
  if (m_iAccum > 100) m_iAccum = 100;
  float i = m_ki * m_iAccum;

  // D
  float d = m_kd * (error / dt);

  return p + i - d;
}

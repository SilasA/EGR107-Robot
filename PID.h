#ifndef PID_H
#define PID_H

class PID
{
private:
  float m_kp;
  float m_ki;
  float m_kd;

  float m_iAccum;
  unsigned long m_lastT;

  float m_maxOut;
  float m_minOut;

public:
  PID(float kp, float ki, float kd, float max, float min);
  PID(float kp, float ki, float kd);

  void SetPID(float kp, float ki, float kd);
  void SetOutput(float max, float min);

  void ResetIAccum();

  float Run(float input, float setpoint);
};

#endif // PID_H

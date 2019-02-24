#ifndef DRIVE_H
#ifndef DRIVE_H

class Drive : public Command
{
private:
  bool m_isDistance;
  float m_value;
  float m_ramp;
  long m_duration;

  unsigned long m_startTime;
  float m_currentValue;

public:
  Drive(float value, float ramp, long duration, bool isDistance = false);
  void Init();
  void Run();
  bool Finished();
  void End();
};

#endif // DRIVE_H

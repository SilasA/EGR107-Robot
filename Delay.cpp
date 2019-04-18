#include "Delay.h"

Delay::Delay(unsigned long mil)
{
  m_mil = mil;
}

void Delay::Init()
{
  m_start = millis();
}

void Delay::Run()
{
}

bool Delay::Finished()
{
  return millis() >= m_start + m_mil;
}

void Delay::End()
{
}

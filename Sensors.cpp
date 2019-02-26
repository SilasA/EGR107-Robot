#include "Sensors.h"

Sensors::Sensors(const char *name, int irLeft, int irRight,
                 int sonarTrig, int sonarEcho) :
                 m_left(irLeft), m_right(irRight), m_ballSonar(sonarTrig, sonarEcho)
{

}

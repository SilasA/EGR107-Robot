#include "FollowWall.h"
#include "Constants.h"

FollowWall::FollowWall(float distance) : 
  Command()
{
    m_distance = distance;
    m_drive = &Command::driveTrain;
    m_sensors = &Command::sensors;
}

void FollowWall::Init()
{
    m_pid = new PID(P, I, D, 200, -200);
    m_isLeftWall = m_sensors->GetLeftFilter() < m_sensors->GetRightFilter();
}

void FollowWall::Run()
{
    float output;
    if (m_isLeftWall)
        output = m_pid->Run(m_sensors->GetLeftFilter(), m_distance);
    else
        output = m_pid->Run(m_sensors->GetRightFilter(), m_distance);
    m_drive->ArcadeDrive(.5, output / 200);
}

bool FollowWall::Finished()
{
    float ld = m_drive->GetLeftDistance();
    float rd = m_drive->GetRightDistance();
    return abs(m_distance - ld) > 10 || abs(m_distance - rd) > 10;
}

void FollowWall::End()
{
    delete m_pid;
}

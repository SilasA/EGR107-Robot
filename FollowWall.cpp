#include "FollowWall.h"
#include "Constants.h"
#include "Turn.h"

FollowWall::FollowWall(float space, float distance) :
  Command()
{
    m_distance = distance;
    m_space = space;
    m_drive = &Command::driveTrain;
    m_sensors = &Command::sensors;
    m_lastDistanceFromWall = 0;
}

void FollowWall::Init()
{
    m_pid = new PID(P, I, D, 0, -150);
    m_isLeftWall = m_sensors->GetLeftFilter() < m_sensors->GetRightFilter();
}

void FollowWall::Run()
{
    if (m_foundGoal && m_isLeftWall) //|| m_drive->IsStalled() && !m_isLeftWall)
    {
      Command::Push(new Turn(50)); // Turn Left
    }
    else if (m_foundGoal && !m_isLeftWall) // || m_drive->IsStalled() && m_isLeftWall)
    {
      Command::Push(new Turn(-50)); // Turn Right
    }
    

    float output;
    if (m_isLeftWall)
        output = m_pid->Run(m_sensors->GetLeft(), m_space);
    else
        output = m_pid->Run(m_sensors->GetRight(), m_space);
    Serial.println(-output);

    m_drive->Drive(.4, -output);
    
    //m_drive->ArcadeDrive(.4, -output / 100);
    //Serial.println("Following");
}

bool FollowWall::Finished()
{
    float ld = m_drive->GetLeftDistance();
    float rd = m_drive->GetRightDistance();
    return abs(m_distance - ld) < 10 || abs(m_distance - rd) < 10
        || m_foundGoal; // || m_drive->IsStalled();
}

void FollowWall::End()
{
    m_drive->Drive(0, 0);
    delete m_pid;
}

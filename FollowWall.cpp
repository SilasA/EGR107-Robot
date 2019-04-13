#include "FollowWall.h"
#include "Constants.h"
#include "Turn.h"
#include "GoalFinder.h"
#include "Drive.h"
#include "SweepBackwards.h"
#include "SweepForwards.h"
#include "SweepStop.h"

FollowWall::FollowWall(float space, float distance) :
  Command()
{
    m_distance = inch_to_count(distance);
    m_space = space;
    m_drive = &Command::driveTrain;
    m_sensors = &Command::sensors;
    m_lastDistanceFromWall = 0;
}

void FollowWall::Init()
{
    m_pid = new PID(P, I, D, 100, -100);
    m_isLeftWall = m_sensors->GetLeftFilter() < m_sensors->GetRightFilter();

    m_startTime = millis();
}

void FollowWall::Run()
{
  float output;
    if (m_isLeftWall)
    {
        output = m_pid->Run(m_sensors->GetLeft(), m_space);
        m_goalFinder.Process(m_sensors->GetLeft());
        Serial.print("PID L In: ");
        Serial.println(m_sensors->GetLeft(), m_space);
    }
    else
    {
        output = m_pid->Run(m_sensors->GetRight(), m_space);
        m_goalFinder.Process(m_sensors->GetRight());
        Serial.print("PID R In: ");
        Serial.println(m_sensors->GetLeft(), m_space);
    }
    Serial.print("Output PID: ");
    Serial.println((m_isLeftWall ? -output : output));


  m_foundGoal = m_goalFinder.FoundGoal();

    if (m_foundGoal && m_isLeftWall) //|| m_drive->IsStalled() && !m_isLeftWall)
    {
      Command::Push(new Turn(-90)); // Turn Left
    }
    else if (m_foundGoal && !m_isLeftWall) // || m_drive->IsStalled() && m_isLeftWall)
    {
      Command::Push(new Turn(90)); // Turn Right
    }

    m_frontWall = Command::sensors.AtWall();

    m_stalled = Command::driveTrain.IsStalled();
    //m_drive->Drive(.4, output);

    m_drive->ArcadeDrive(.75, (m_isLeftWall ? -output : output) / 200.0);
    //Serial.println("Following");
}

bool FollowWall::Finished()
{
    float ld = m_drive->GetLeftDistance();
    float rd = m_drive->GetRightDistance();
    return m_distance - ld < 0 || m_distance - rd < 0 ||
      (m_startTime + 1000 <= millis() && m_stalled) ||
      m_frontWall || m_foundGoal;
}

void FollowWall::End()
{
  if (m_stalled)
  {
    Serial.print("Stalled");
    //Command::Push(new SweepStop());
    Command::Push(new Drive(150, -1, -9, true));
    Command::Push(new Turn(-30));
    //Command::Push(new SweepForwards());
    Command::Push(new Drive(150, -1, 40, true));
  }
  else if (m_frontWall)
  {
    Serial.print("Wall");
    if (m_isLeftWall)
      Command::Push(new Turn(90));
    else Command::Push(new Turn(-90));
    Command::Push(new FollowWall(12, 60));
  }
  else if (m_foundGoal)
  {
    Serial.print("Goal");
    Command::Push(new Drive(100, -1, 8, true));
    if (m_isLeftWall)
      Command::Push(new Turn(270));
    else Command::Push(new Turn(-270));
    Command::Push(new SweepBackwards());
    Command::Push(new Drive(100, -1, -14, true));
    Command::Push(new Turn(-180));
    Command::Push(new Drive(120, -1, 50, true));
  }

    //m_drive->Drive(0, 0);
    delete m_pid;
}

#ifndef FOLLOW_WALL_H
#define FOLLOW_WALL_H

#include "Command.h"
#include "PID.h"
#include "GoalFinder.h"

class FollowWall : public Command
{
private:
    DriveTrain *m_drive;
    Sensors *m_sensors;

    GoalFinder m_goalFinder;

    PID *m_pid;
    float m_distance;
    float m_space;

    long m_startTime;

    float m_lastDistanceFromWall;

    bool m_isLeftWall = false;
    bool m_stalled = false;
    bool m_foundGoal = false;
    bool m_frontWall = false;

public:
    FollowWall(float space, float distance);
    void Init();
    void Run();
    bool Finished();
    void End();
};

#endif // FOLLOW_WALL_H

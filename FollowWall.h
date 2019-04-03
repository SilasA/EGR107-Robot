#ifndef FOLLOW_WALL_H
#define FOLLOW_WALL_H

#include "Command.h"
#include "PID.h"

class FollowWall : public Command
{
private:
    DriveTrain *m_drive;
    Sensors *m_sensors;

    PID *m_pid;
    float m_distance;
    float m_space;

    float m_lastDistanceFromWall;

    bool m_isLeftWall = false;
    bool m_foundGoal = false;

public:
    FollowWall(float space, float distance);
    void Init();
    void Run();
    bool Finished();
    void End();
};

#endif // FOLLOW_WALL_H

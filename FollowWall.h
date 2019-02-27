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

    bool m_isLeftWall;

public:
    FollowWall(float distance);
    void Init();
    void Run();
    bool Finished();
    void End();
};

#endif // FOLLOW_WALL_H

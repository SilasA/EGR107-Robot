#ifndef COMMAND_H
#define COMMAND_H

#include "Arduino.h"
#include "DriveTrain.h"
#include "Sensors.h"

class Command;

// Node for Command Queue
struct node_t {
  Command *cmd;
  node_t *next;
  node_t *prev;
};

//
class Command
{
private:
  static bool changed;

public:
  static node_t *front;
  static node_t *back;

  // Constructor
  Command();

  // Initializes Command
  // Called once when command is activated
  virtual void Init();

  // Executes Command
  // Called repeatedly during command execution
  virtual void Run();

  // Checks whether or not command is Finished
  // Called every iteration after Run
  virtual bool Finished();

  // Called when command is finished
  virtual void End();

  // Utility functions
  int32_t inch_to_count(float inches)
  {
    return inches / INCH_PER_REV * COUNTS_PER_REV;
  }

  int32_t deg_to_count(float deg)
  {
    return inch_to_count(deg * INCH_PER_DEG);
  }

  // Static methods/members

  static DriveTrain driveTrain;
  static Sensors sensors;

  static int commandsQueued;

  // Pushes a new command to the schedule
  static void Push(Command *cmd);

  // Returns reference to top Command
  static Command* Peek();

  // Pops top command from schedule
  // TODO: Return Command?
  static void Pop();

  // Called every loop in main
  static void RunScheduler();
};

#endif // COMMAND_H

#ifndef COMMAND_H
#define COMMAND_H

#include <stack>

//
struct node_t {
    Command *command;
    node_t *next;
};

//
class Command
{
private:
  static node_t *top;
  static bool changed;

public:
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

  // Static methods

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

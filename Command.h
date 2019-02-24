#ifndef COMMAND_H
#define COMMAND_H

class Command;

// Node for Command Queue
struct node_t {
  Command *cmd;
  node_t *next;
  node_t *prev;
}

//
struct node_t {
    Command *command;
    node_t *next;
};

//
class Command
{
private:
<<<<<<< HEAD
  static node_t *front;
  static node_t *back;
  bool changed;
=======
  static node_t *top;
  static bool changed;
>>>>>>> ab5c6d99b22e6063de19f276e7b0c5ad90492987

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

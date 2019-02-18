#include "Command.h"

// Static
std::stack<Command*> Command::schedule;

static void Command::Push(Command *cmd)
{
  schedule.push(cmd);
}

static Command* Command::Peek()
{
  return schedule.top();
}

static void Command::Pop()
{
  schedule.top()->End();
  delete schedule.top();
  schedule.pop();
}

static void RunScheduler()
{
  if (changed)
  {
    changed = false;
    if (schedule.top())
      schedule.top()->Init();
  }

  if (schedule.top())
    schedule.top()->Run()
}

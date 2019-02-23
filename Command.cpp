#include "Command.h"

// Static
node_t *Command::top;

static void Command::Push(Command *cmd)
{
  node_t *node = new node_t();
  node->command = cmd;
  if (top)
    node->next = top;
  else node->next = nullptr;
  top = node;
  changed = true;
}

static Command* Command::Peek()
{
  return top->command;
}

static void Command::Pop()
{
  node_t *next = top->next;
  delete top->command;
  delete top;
  top = next;
  changed = true;
}

static void RunScheduler()
{
  if (changed)
  {
    changed = false;
    if (top)
      top->command->Init();
  }

  if (top)
    top->command->Run()
}

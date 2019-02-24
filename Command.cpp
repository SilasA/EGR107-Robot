#include "Command.h"

// Static
<<<<<<< HEAD
node_t *Command::front;
node_t *Command::back;

static void Command::Push(Command *cmd)
{
  changed = true;
  node_t *temp = new node_t();
  temp->cmd = cmd;
  temp->next = nullptr;
  temp->prev = Command::back;

  if (Command::back)
  {
    Command::back->next = temp;
  }
  else
  {
    Command::back = temp;
    Command::front = temp;
  }
=======
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
>>>>>>> ab5c6d99b22e6063de19f276e7b0c5ad90492987
}

static Command* Command::Peek()
{
<<<<<<< HEAD
  return Command::front->cmd;
=======
  return top->command;
>>>>>>> ab5c6d99b22e6063de19f276e7b0c5ad90492987
}

static void Command::Pop()
{
<<<<<<< HEAD
  changed = true;
  Command::front->cmd->End();
  node_t *temp = Command::front->next
  delete Command::front->cmd;
  delete Command::front
  Command::front = temp;
=======
  node_t *next = top->next;
  delete top->command;
  delete top;
  top = next;
  changed = true;
>>>>>>> ab5c6d99b22e6063de19f276e7b0c5ad90492987
}

static void RunScheduler()
{
  if (Command::front->cmd->Finished())
  {
    Pop();
  }

  if (changed)
  {
    changed = false;
<<<<<<< HEAD
    if (Command::front)
      Command::front->cmd->Init();
  }

  if (Command::front)
    Command::front->cmd->Run()
=======
    if (top)
      top->command->Init();
  }

  if (top)
    top->command->Run()
>>>>>>> ab5c6d99b22e6063de19f276e7b0c5ad90492987
}

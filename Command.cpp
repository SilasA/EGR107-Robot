#include "Command.h"
#include "Constants.h"

// Static
node_t *Command::front;
node_t *Command::back;

bool Command::changed = true;

Command::Command()
{
}

// static
DriveTrain Command::driveTrain = DriveTrain("Drive Train", LEFT_PIN, LEFT_HB1, LEFT_HB2, RIGHT_PIN, RIGHT_HB1, RIGHT_HB2);

void Command::Push(Command *cmd)
{
  Command::changed = true;
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
}

Command* Command::Peek()
{
  return Command::front->cmd;
}

void Command::Pop()
{
  Command::changed = true;
  Command::front->cmd->End();
  node_t *temp = Command::front->next;
  delete Command::front->cmd;
  delete Command::front;
  Command::front = temp;
}

void Command::RunScheduler()
{
  if (Command::front->cmd->Finished())
  {
    Pop();
  }

  if (Command::changed)
  {
    Command::changed = false;
    if (Command::front)
      Command::front->cmd->Init();
  }

  if (Command::front)
    Command::front->cmd->Run();
}

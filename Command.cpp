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
DriveTrain Command::driveTrain = DriveTrain("Drive Train", LEFT_PIN, LEFT_HB1, LEFT_HB2, RIGHT_PIN, RIGHT_HB1, RIGHT_HB2, ENC_LEFT_A, ENC_LEFT_B, ENC_RIGHT_A, ENC_RIGHT_B, SWEEPER_PIN);
Sensors Command::sensors = Sensors("Sensors", (int)IR_LEFT, (int)IR_RIGHT, (int)IR_FRONT, (int)IR_BEACON, SONAR_FRONT_TRIG, SONAR_FRONT_ECHO);

int Command::commandsQueued = 0;

void Command::Push(Command *cmd)
{
  //Serial.println("Pushed");
  Command::changed = true;
  node_t *temp = new node_t();
  temp->cmd = cmd;

  if (Command::front == nullptr)
    back = front = temp;
  else
  {
    temp->prev = back;
    back->next = temp;
    back = temp;
  }
}

Command* Command::Peek()
{
  return Command::front->cmd;
}

void Command::Pop()
{
  //Serial.println("Popped");
  if (front == nullptr) return;
  Command::changed = true;
  Command::front->cmd->End();

  node_t *temp = Command::front;
  front = front->next;

  if (front == nullptr)
    back = nullptr;
  else
    front->prev = nullptr;
  delete temp;
  //Serial.println(Command::front->next != nullptr);
}

void Command::RunScheduler()
{
  if (Command::front == nullptr) return;
  if (Command::changed)
  {
    Serial.println("Initialized");
    Command::changed = false;
    if (Command::front)
      Command::front->cmd->Init();
  }

  if (Command::front)
    Command::front->cmd->Run();

   if (Command::front->cmd->Finished())
    {
    Serial.println("Finished");
    Pop();
    }
}

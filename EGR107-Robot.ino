#include "Command.h"
#include "Constants.h"

#include "FollowWall.h"
#include "Drive.h"
#include "Turn.h"
#include "Delay.h"
#include "SweepForwards.h"
#include "SweepBackwards.h"
#include "ArcadeTurn.h"

long time = millis();
bool trig = false;

// ENCODERS Shotty when used above 100 speed

void setup() {
  // put your setup code here, to run once:

  Command::Push(new SweepForwards());
  //Command::Push(new Turn(90));
  //Command::Push(new Delay(3000));
  //Command::Push(new FollowWall(12, 300));
  Command::Push(new Drive(150, -1, 50, true));
  //Command::Push(new Turn(-90));
  /*Command::Push(new Drive(180, -1, 13, true));
  Command::Push(new SweepBackwards());
  Command::Push(new Delay(1000));
  Command::Push(new Drive(100, -1, -10, true));
  Command::Push(new Turn(90));
  Command::Push(new Turn(90));
  Command::Push(new Drive(100, -1, 12, true));
  Command::Push(new Turn(90));
  Command::Push(new Turn(90));
  Command::Push(new Turn(90));
  Command::Push(new Drive(150, -1, 34, true));
  Command::Push(new Turn(-90));
  Command::Push(new Drive(180, -1, 13, true));
  Command::Push(new SweepBackwards());
  Command::Push(new Delay(1000));
  Command::Push(new Drive(100, -1, -10, true));*/

  Serial.begin(9600);
  Serial.println("Starting");

  time = millis();

  Command::driveTrain.Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(Command::driveTrain.IsStalled());

  /*if (Command::commandsQueued > 4)
  {
    Command::front = nullptr;
  }*/
  
  if (Command::front == nullptr)
  {
    //Command::Push(new SweepForwards());
    Command::Push(new Drive(120, -1, 50, true));
    /*Command::Push(new Turn(-45));
    Command::Push(new Drive(100, -1, 6, true));
    Command::Push(new Turn(-90));
    Command::Push(new Drive(100, -1, 15, true));
    Command::Push(new SweepBackwards());
    Command::Push(new Drive(100, -1, -12, true));
    Command::Push(new Drive(0, -1, 0, true));*/
  }

  if (time + 165000 <= millis() && !trig)
  {
    Command::Push(new SweepBackwards());
    Command::Push(new ArcadeTurn(1.0));
    trig = true;
  }
  //Serial.println(Command::front != nullptr);
  //Command::driveTrain.Sweep(-.4);
  //Command::driveTrain.ArcadeDrive(.5, 0);

  Serial.print(Command::sensors.GetLeftFilter());
  Serial.print("\t");
  Serial.print(Command::sensors.GetRightFilter());
  Serial.print("\t");
  Serial.print(Command::sensors.GetFrontFilter());
  Serial.print("\t");
  Serial.print(Command::sensors.GetFrontTopFilter());
  Serial.print("\t");
  Serial.print(Command::driveTrain.GetLeftDistance());
  Serial.print("\t");
  Serial.println(Command::driveTrain.GetRightDistance());

  Command::driveTrain.CalcStalled();
  Command::RunScheduler();
}

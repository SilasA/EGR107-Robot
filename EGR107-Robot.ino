#include "Command.h"
#include "Constants.h"

#include "FollowWall.h"
#include "Drive.h"
#include "Turn.h"

long time = 0;


// ENCODERS Shotty when used above 100 speed

void setup() {
  // put your setup code here, to run once:
  //Command::Push(new FollowWall(12, 7000));
  //Command::Push(new Drive(-100, -1, 1000, false));
  Command::Push(new Turn(1755));
  Serial.begin(9600);
  Serial.println("Starting");

  time = millis();

  Command::driveTrain.Init(); 
}

void loop() {
  // put your main code here, to run repeatedly:
  /*if (Command::front == nullptr)
  {
    Command::Push(new FollowWall(2500));
  }*/
  //Serial.println(Command::front != nullptr);
  //Command::driveTrain.Sweep(-.1);

  Serial.print(Command::sensors.GetLeftFilter());
  Serial.print("\t");
  Serial.print(Command::sensors.GetRightFilter());
  Serial.print("\t");
  Serial.print(Command::sensors.GetFrontFilter());
  Serial.print("\t");
  Serial.print(Command::driveTrain.GetLeftDistance());
  Serial.print("\t");
  Serial.println(Command::driveTrain.GetRightDistance());
  //Serial.println("Hello World");

  Command::RunScheduler();
}

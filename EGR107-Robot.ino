#include "Command.h"
#include "Constants.h"
#include "FollowWall.h"

// ENCODERS Shotty when used above 100 speed

void setup() {
  // put your setup code here, to run once:
  Command::Push(new FollowWall(1000));
  Serial.begin(9600);
  Serial.println("Starting");
}

void loop() {
  // put your main code here, to run repeatedly:
  Command::RunScheduler();
}

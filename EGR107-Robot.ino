#include "Command.h"
#include "Constants.h"
#include "Drive.h"
#include "DriveTriangle.h"
#include "Turn.h".

void setup() {
  // put your setup code here, to run once:
  Command::Push(new DriveTriangle());
  Serial.begin(9600);
  Serial.println("Restarting");
}

void loop() {
  // put your main code here, to run repeatedly:
  Command::RunScheduler();
}

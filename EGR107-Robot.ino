#include "Command.h"
#include "Constants.h"
#include "Drive.h"

void setup() {
  // put your setup code here, to run once:
  Command::Push(new Drive(250, 2, 3000));
  Serial.begin(9600);
  Serial.println("Restarting");
}

void loop() {
  // put your main code here, to run repeatedly:
  Command::RunScheduler();
}

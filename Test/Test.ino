void setup() {
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);

  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);

  analogWrite(5, 250);
  analogWrite(6, 250);
}

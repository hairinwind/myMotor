int enA = 14; // 9 

int in1 = 12;
int in2 = 27;

int enB = 32;
int in3 = 25;
int in4 = 33;

void setup() {
  // set all pin mode to putout
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  driveRightForward(120);
  driveLeftBackward(120);
  delay(8000);

  // //turn off
  stopRight();
  stopLeft();
}

void loop() {
  // test(enB);
  
  // driveRightForward(80);
  // driveLeftForward(80);
  // delay(2000);
  // driveRightBackward(80);
  // driveLeftBackward(80);
  // delay(2000);

  // analogWrite(enB, 255);
  // analogWrite(in1, 255);
  // analogWrite(in2, 255);
  // analogWrite(in3, 255);
  // analogWrite(in4, 255);
  
  // digitalWrite(enA, HIGH);
  // digitalWrite(in2, HIGH);
  // 将LED置为HIGH，使其常亮
  //digitalWrite(LED_BUILTIN, HIGH);

  // directionControl();
}

void driveRightForward(int speed) {
  analogWrite(enA, speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void driveRightBackward(int speed) {
  analogWrite(enA, speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void stopRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void stopLeft() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void driveLeftForward(int speed) {
  analogWrite(enB, speed);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void driveLeftBackward(int speed) {
  analogWrite(enB, speed);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}


void test(int pin) {
  analogWrite(pin, 255);
  delay(1000);
  analogWrite(pin, 200);
  delay(1000);
  analogWrite(pin, 150);
  delay(1000);
  analogWrite(pin, 100);
}

void directionControl() {
  // set channel A 
  analogWrite(enA, 255);

  //turn on
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(3000);

  //switch 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(3000);

  //turn off
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
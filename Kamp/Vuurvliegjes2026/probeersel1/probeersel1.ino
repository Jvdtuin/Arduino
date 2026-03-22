#include <Servo.h>

Servo servo;
const int redLed = 7;
const int greenLed =8;
const int blueLed = 12;


void setup() {
  // put your setup code here, to run once:
  servo.attach(10);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);

  servo.write(90);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, HIGH);
  digitalWrite(blueLed, HIGH);
  delay(2000);
  servo.write(0);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  digitalWrite(blueLed, LOW);
  delay(700);
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, HIGH);
  digitalWrite(blueLed, HIGH);
  delay(1300);
  servo.write(180);
    digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
  digitalWrite(blueLed, LOW);
  delay(700);
}

// Aggressive Robot
// Calm until an object appears, then charges forward aggressively.

#include "distance_utils.h"

// Motor pins
int leftMotorEnable = 9, leftMotorIn1 = 7, leftMotorIn2 = 8;
int rightMotorEnable = 3, rightMotorIn1 = 4, rightMotorIn2 = 5;
// Ultrasonic sensor pins
int trigPin = 10, echoPin = 11;
// Status LEDs
int ledOn = 19, ledWarning = 18;

int attackThreshold = 50;
bool aggressive = false;

void setup() {
  pinMode(leftMotorEnable, OUTPUT); pinMode(leftMotorIn1, OUTPUT); pinMode(leftMotorIn2, OUTPUT);
  pinMode(rightMotorEnable, OUTPUT); pinMode(rightMotorIn1, OUTPUT); pinMode(rightMotorIn2, OUTPUT);
  pinMode(trigPin, OUTPUT); pinMode(echoPin, INPUT);
  pinMode(ledOn, OUTPUT); pinMode(ledWarning, OUTPUT);
  digitalWrite(ledOn, HIGH);
  Serial.begin(9600);
}

void loop() {
  int distance = calculateDistance(trigPin, echoPin);
  Serial.println(distance);

  if (distance >= attackThreshold && !aggressive) {
    digitalWrite(leftMotorIn1, HIGH); digitalWrite(rightMotorIn1, HIGH);
  } else if (distance < attackThreshold) {
    analogWrite(rightMotorEnable, 240); analogWrite(leftMotorEnable, 240);
    digitalWrite(ledWarning, HIGH);
    delay(2000);
    digitalWrite(leftMotorIn1, LOW); digitalWrite(rightMotorIn1, LOW);
    digitalWrite(leftMotorIn2, LOW); digitalWrite(rightMotorIn2, LOW);
    aggressive = true;
  }
}

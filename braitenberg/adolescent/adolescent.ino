// Adolescent Robot (3 States)
// Cycles between explorer, offended, and aggressive states.

#include "distance_utils.h"

// Motor pins
int leftMotorEnable = 9, leftMotorIn1 = 7, leftMotorIn2 = 8;
int rightMotorEnable = 3, rightMotorIn1 = 4, rightMotorIn2 = 5;
// Ultrasonic sensor pins
int trigPin = 10, echoPin = 11;

int maxSpeed = 180;
int stopThreshold = 30;

int state = 0; // 0 = explorer, 1 = offended, 2 = aggressive
long stateStartTime = millis();
long stateInterval = 20000; // 20 seconds per state

void setup() {
  pinMode(leftMotorEnable, OUTPUT); pinMode(rightMotorEnable, OUTPUT);
  pinMode(leftMotorIn1, OUTPUT); pinMode(leftMotorIn2, OUTPUT);
  pinMode(rightMotorIn1, OUTPUT); pinMode(rightMotorIn2, OUTPUT);
  pinMode(trigPin, OUTPUT); pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int distance = calculateDistance(trigPin, echoPin);

  if (state == 0) {
    if (distance > stopThreshold) {
      analogWrite(rightMotorEnable, maxSpeed);
      analogWrite(leftMotorEnable, maxSpeed);
      digitalWrite(rightMotorIn1, HIGH); digitalWrite(leftMotorIn1, HIGH);
    }
  } else if (state == 1) {
    if (distance < stopThreshold) {
      digitalWrite(rightMotorIn1, HIGH); digitalWrite(leftMotorIn2, HIGH);
      delay(500);
    }
  } else if (state == 2) {
    if (distance < stopThreshold) {
      analogWrite(rightMotorEnable, 240); analogWrite(leftMotorEnable, 240);
      delay(2000);
    }
  }

  if (millis() - stateStartTime > stateInterval) {
    state = (state + 1) % 3; // cycle states
    stateStartTime = millis();
  }
}

// Offended Robot
// Turns away from object and stays 'offended' (won't move forward).

#include "distance_utils.h"

// Motor pins
int leftMotorEnable = 9, leftMotorIn1 = 7, leftMotorIn2 = 8;
int rightMotorEnable = 3, rightMotorIn1 = 4, rightMotorIn2 = 5;
// Ultrasonic sensor pins
int trigPin = 10, echoPin = 11;
// Status LEDs
int ledOn = 19, ledWarning = 18;

int stopThreshold = 30;
int maxSpeed = 180;
bool offended = false;

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

  if (distance >= stopThreshold && !offended) {
    analogWrite(rightMotorEnable, maxSpeed);
    analogWrite(leftMotorEnable, maxSpeed);
    digitalWrite(leftMotorIn1, HIGH); digitalWrite(rightMotorIn1, HIGH);
  } else if (distance < stopThreshold) {
    digitalWrite(ledWarning, HIGH);
    digitalWrite(leftMotorIn1, LOW); digitalWrite(rightMotorIn1, LOW);
    delay(500);
    digitalWrite(rightMotorIn1, HIGH); digitalWrite(leftMotorIn2, HIGH);
    delay(550);
    offended = true;
  }
}

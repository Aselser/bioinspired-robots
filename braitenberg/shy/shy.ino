// Shy Robot
// Moves forward, slows down when an object is near, stops if too close.

#include "distance_utils.h"

// Motor pins
int leftMotorEnable = 9, leftMotorIn1 = 7, leftMotorIn2 = 8;
int rightMotorEnable = 3, rightMotorIn1 = 4, rightMotorIn2 = 5;
// Ultrasonic sensor pins
int trigPin = 10, echoPin = 11;
// Status LEDs
int ledOn = 19, ledWarning = 18;

// Parameters
int stopThreshold = 30;    // Stop distance (cm)
int slowThreshold = 70;    // Slow down distance (cm)
int maxSpeed = 255;        // Max motor speed
float motorCorrection = 0.95; // Correction factor

void setup() {
  pinMode(leftMotorEnable, OUTPUT); pinMode(leftMotorIn1, OUTPUT); pinMode(leftMotorIn2, OUTPUT);
  pinMode(rightMotorEnable, OUTPUT); pinMode(rightMotorIn1, OUTPUT); pinMode(rightMotorIn2, OUTPUT);
  pinMode(trigPin, OUTPUT); pinMode(echoPin, INPUT);
  pinMode(ledOn, OUTPUT); pinMode(ledWarning, OUTPUT);
  digitalWrite(ledOn, HIGH); // Green LED on = powered
  Serial.begin(9600);
}

void loop() {
  int distance = calculateDistance(trigPin, echoPin);
  Serial.println(distance);

  if (distance >= slowThreshold) {
    // Far: full speed
    analogWrite(rightMotorEnable, maxSpeed);
    analogWrite(leftMotorEnable, maxSpeed * motorCorrection);
    digitalWrite(leftMotorIn1, HIGH); digitalWrite(rightMotorIn1, HIGH);
  } else if (distance > stopThreshold) {
    // Mid-range: proportional slow down
    int speed = (distance - stopThreshold) * maxSpeed / (slowThreshold - stopThreshold);
    analogWrite(rightMotorEnable, speed);
    analogWrite(leftMotorEnable, speed * motorCorrection);
    digitalWrite(leftMotorIn1, HIGH); digitalWrite(rightMotorIn1, HIGH);
  } else {
    // Danger: stop motors, warning LED on
    analogWrite(rightMotorEnable, 0); analogWrite(leftMotorEnable, 0);
    digitalWrite(ledWarning, HIGH);
  }
}

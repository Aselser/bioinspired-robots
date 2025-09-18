// Light Follower (Curious)
// Follows light sources but still avoids obstacles.

#include "distance_utils.h"

// Motor pins
int leftMotorEnable = 9, leftMotorIn1 = 7, leftMotorIn2 = 8;
int rightMotorEnable = 3, rightMotorIn1 = 4, rightMotorIn2 = 5;
// Ultrasonic sensor pins
int trigPin = 10, echoPin = 11;


#define RIGHT_LIGHT A2
#define LEFT_LIGHT A3

int maxSpeed = 180;
int stopThreshold = 30;
int leftLightBaseline, rightLightBaseline;

void setup() {
  pinMode(leftMotorEnable, OUTPUT); pinMode(rightMotorEnable, OUTPUT);
  pinMode(leftMotorIn1, OUTPUT); pinMode(leftMotorIn2, OUTPUT);
  pinMode(rightMotorIn1, OUTPUT); pinMode(rightMotorIn2, OUTPUT);
  pinMode(trigPin, OUTPUT); pinMode(echoPin, INPUT);
  Serial.begin(9600);

  // baseline light levels
  leftLightBaseline = analogRead(LEFT_LIGHT);
  rightLightBaseline = analogRead(RIGHT_LIGHT);
}

void loop() {
  int distance = calculateDistance(trigPin, echoPin);
  int leftLightValue = analogRead(LEFT_LIGHT);
  int rightLightValue = analogRead(RIGHT_LIGHT);

  if (distance >= stopThreshold) {
    if (abs(leftLightValue - rightLightValue) < 15) {
      analogWrite(rightMotorEnable, maxSpeed);
      analogWrite(leftMotorEnable, maxSpeed);
      digitalWrite(rightMotorIn1, HIGH); digitalWrite(leftMotorIn1, HIGH);
    } else if (rightLightValue > rightLightBaseline + 20) {
      analogWrite(rightMotorEnable, maxSpeed - 80);
      analogWrite(leftMotorEnable, maxSpeed);
    } else if (leftLightValue > leftLightBaseline + 20) {
      analogWrite(rightMotorEnable, maxSpeed);
      analogWrite(leftMotorEnable, maxSpeed - 80);
    }
  } else {
    digitalWrite(leftMotorIn1, LOW); digitalWrite(rightMotorIn1, LOW);
    delay(500);
    digitalWrite(rightMotorIn1, HIGH); digitalWrite(leftMotorIn2, HIGH);
    delay(400);
  }
}

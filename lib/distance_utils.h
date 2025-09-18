// distance_utils.h
// Utility function to calculate distance with ultrasonic sensor

#ifndef DISTANCE_UTILS_H
#define DISTANCE_UTILS_H

int calculateDistance(int trigPin, int echoPin) {
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // measure echo time
  return duration * 0.034 / 2;       // convert to cm
}

#endif

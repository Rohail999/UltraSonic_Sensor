#include "NewPing.h"

#define TRIGGER_PIN  A1
#define ECHO_PIN     A2
#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

float distance, duration;
 
void setup() 
{
  Serial.begin (9600);
}
 
void loop() {

  duration = sonar.ping();
  distance = (duration / 2) * 0.0343;
   
  Serial.print("Distance = ");
  if (distance >= 400 || distance <= 2)
  {
   Serial.println("Out of Range"); 
  }
   else {
        Serial.print(distance);   
        Serial.println(" cm");
        delay(500);
  }
delay(500);
} 

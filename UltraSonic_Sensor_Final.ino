#include <NewPing.h>

#include "DHT.h"
#include "NewPing.h"

#define DHTPIN 7
#define DHTTYPE DHT12
#define TRIGGER_PIN  11
#define ECHO_PIN     12
#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

float hum;
float temp;
float duration;
float distance;
float soundsp; //speed of sound in m/s
float soundcm; //speed of sound in cm/ms
int iterations = 5;

DHT dht(DHTPIN, DHTTYPE);
 
void setup() 
{
  Serial.begin (9600);
  dht.begin();
}
 
void loop() {
  delay(2000);

  hum = dht.readHumidity();
  temp= dht.readTemperature();

  soundsp = 331.4 + (0.606 * temp) + (0.0124 * hum);

  soundcm = soundsp / 10000;

  duration = sonar.ping_median(iterations);
  distance = (duration / 2) * soundcm;

  Serial.print("Sound speed: ");
  Serial.print(soundsp);
  Serial.print(" m/s, ");
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Current Temperature: ");
  Serial.print(temp);
  Serial.print(" C, ");
  Serial.print("Distance: ");
  
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

  Serial.println(" ");
}   

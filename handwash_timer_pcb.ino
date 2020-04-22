#define trigPin 13
#define echoPin 12
#define redLED 11
#define grnLED 10

#include "SevSeg.h"
SevSeg sevseg;

void setup() {
  // Timer setup
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
  bool resistorsOnSegments = true;

  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);

  // Motion sensor setup
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(grnLED, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  if(distance < 20) {  // If an object comes close to sensor, i.e, someone starts washing hands
   for(int i = 20; i >= 0; i--){
        sevseg.setNumber(i, -1);
        delay(1000);
        
        long duration, distance;
        digitalWrite(trigPin, LOW);  // Added this line
        delayMicroseconds(2); // Added this line
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10); // Added this line
        digitalWrite(trigPin, LOW);
        duration = pulseIn(echoPin, HIGH);
        distance = duration * 0.034 / 2;
        
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.print(" cm\n");
        digitalWrite(redLED,HIGH); // When the Red condition is met, the Green LED should turn off
        digitalWrite(grnLED,LOW);
      
        if (distance > 50 || distance == 0) {
          digitalWrite(redLED,LOW);
          digitalWrite(grnLED,HIGH);
        }
        sevseg.refreshDisplay(); 
   } 
   digitalWrite(redLED, LOW);
   digitalWrite(grnLED, LOW);
   delay(5000);
  }
}

// Created By Aswin kulatilleke
// Code for IOT Dashboard

#define ULTRASONIC_TRIG_PIN 2 // pin TRIG is D11 PIN in NODE MCU BOARD 
#define ULTRASONIC_ECHO_PIN 0 //pin ECHO is D12 PIN in NODE MCU BOARD
#include "thingProperties.h"

void setup () {
Serial.begin (9600);
delay (1500);

initProperties ();

ArduinoCloud.begin (ArduinoIoTPreferredConnection);

setDebugMessageLevel (2);
ArduinoCloud.printDebugInfo ();

pinMode (ULTRASONIC_TRIG_PIN, OUTPUT); // The trigger is defined as output
pinMode (ULTRASONIC_ECHO_PIN, INPUT); // The Echo is defined as input
}

void loop () {
ArduinoCloud.update ();

long duration, Distance_Sensor;
digitalWrite (ULTRASONIC_TRIG_PIN, LOW);
delayMicroseconds (2);

digitalWrite (ULTRASONIC_TRIG_PIN, HIGH); // With this we send an ultrasonic sound
delayMicroseconds (10); // We will send for 10 milliseconds

digitalWrite (ULTRASONIC_TRIG_PIN, LOW); // Now we stop transmitting
duration = pulseIn (ULTRASONIC_ECHO_PIN, HIGH); // Here we measure how long it takes before we get the ultrasound back.
distance = (duration / 2) / 29.1; // With this we ensure that the values ​​in cm are displayed in the IoT cloud
Serial.print ("Distance:"); // To be able to check whether everything is working without an IoT Cloud connection, we also display it in the Monitor
Serial.print (distance);
Serial.println ("cm");
}
/*
  Since Led is READ_WRITE variable, onLedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLedChange()  {
  // Add your code here to act upon Led change
}
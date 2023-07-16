// Aswin Kulatilleke
// Arduino NRF24L01 Transmitter - Switch

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN CONNECT TO UNO DIGITAL PIN CE TO PIN 9 & CSN TO PIN 10

int s1 = 2;
int joy2Y = 3;


const byte address[6] = "10011";
int data[2];

void setup() { 
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  //radio.stopListening();
 
  pinMode(s1, INPUT_PULLUP);
  pinMode(joy2Y, INPUT);


}
void loop() {
  radio.stopListening();
  data[0] = digitalRead(s1);
  data[1] = analogRead(joy2Y);
  radio.write(&data, sizeof(data));
  
}

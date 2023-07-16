//Created by Aswin Kulatilleke
//Arduino NRF24L01 Receiver - Relay control + Motor control

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN    CONNECT TO UNO DIGITAL PIN CE TO PIN 9 & CSN TO PIN 10
const byte address[6] = "10011";


const int relay = 4; //CONNECT TO RELAY IN PIN to pin 4


// Motor A connections
//int enA = 9;
int in1 = 8; // CONNECT TO UNO DIGITAL PIN 8
int in2 = 7;// CONNECT TO UNO DIGITAL PIN 7
// Motor B connections
//int enB = 3;
int in3 = 6; // CONNECT TO UNO DIGITAL PIN 6
int in4 = 5; // // CONNECT TO UNO DIGITAL PIN 5

//int buttonState = 0;
int data[2];
int val;
int LED1 =3;
int LED2= 2;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  pinMode(relay, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

 
  
}

void loop() {
  
   radio.startListening();
  if (radio.available()) {
    radio.read(&data, sizeof(data));
    state(data[0], data[1]);
    radio.stopListening();
  }
}
  
  void state( int s1,int joy2Y) {
   Serial.println(joy2Y);
   val = joy2Y;

   Serial.print("Y-axis: ");
   Serial.print(analogRead(joy2Y));
   Serial.println(" | ");
   delay(200);

  if (s1 == 0) {
    digitalWrite(relay, HIGH);
  } else {
    digitalWrite(relay, LOW);
  }

  if (val > 600) {
    //digitalWrite(LED1, HIGH);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    //delay(1000);

  } else {
    //digitalWrite(LED1, LOW);
    
  }

 if (val < 400) {
    //digitalWrite(LED2, HIGH);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(1000);
  } else {
    ;

  }

  if (val > 400 && val < 600) {
    //digitalWrite(LED2, LOW);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  } else {
    


  }

}

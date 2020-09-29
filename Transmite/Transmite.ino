#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
const int joystickX = A0;
const int joystickY = A1;

const byte PIN_BUTTON_RIGHT = 0;
const byte PIN_BUTTON_UP = 1;
const byte PIN_BUTTON_DOWN = 2;
const byte PIN_BUTTON_LEFT = 3;
int sensorValueX;
int sensorValueY;
int botonOprimido=0;
int msg[6] ;
void setup() {
  pinMode(PIN_BUTTON_RIGHT, INPUT); 
  //digitalWrite(PIN_BUTTON_RIGHT, HIGH);
  pinMode(PIN_BUTTON_LEFT, INPUT);  
  //digitalWrite(PIN_BUTTON_LEFT, HIGH);
  pinMode(PIN_BUTTON_UP, INPUT);  
  //digitalWrite(PIN_BUTTON_UP, HIGH);
  pinMode(PIN_BUTTON_DOWN, INPUT);  
  //digitalWrite(PIN_BUTTON_DOWN, HIGH);

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  Serial.begin(9600);
  sensorValueX = analogRead(joystickX);
  sensorValueY = analogRead(joystickY);
  msg[0] = sensorValueX ;
  msg[1] = sensorValueY ;
  msg[2]=digitalRead(PIN_BUTTON_RIGHT);
  msg[3]=digitalRead(PIN_BUTTON_UP);
  msg[4]=digitalRead(PIN_BUTTON_DOWN);
  msg[5]=digitalRead(PIN_BUTTON_LEFT);
  
  radio.write(msg,sizeof(msg));
  //Serial.print("Envio 1 ---");
  //Serial.print(digitalRead(PIN_BUTTON_RIGHT));
  Serial.println();
  //Serial.print("Envio 2 ---");
  //Serial.print(digitalRead(PIN_BUTTON_UP));
  Serial.println();
  //Serial.print("Envio 3 ---");
  //Serial.print(digitalRead(PIN_BUTTON_DOWN));
  Serial.println();
  //Serial.print("Envio 4 ---");
  //Serial.print(digitalRead(PIN_BUTTON_LEFT));
  Serial.println();
  //Serial.print(sensorValueX);
  //Serial.println();

  delay(10);
}

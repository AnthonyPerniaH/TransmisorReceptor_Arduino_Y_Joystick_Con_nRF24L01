
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
const int p2=2;
const int p3=3;
const int p4=4;
const int p5=5;
const int p9=9;
const int p10=10;
const int p11=11;
const int p12=12;
int msg[6];
int x;
int y;
void setup() {
  Serial.begin(9600);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
  pinMode(p5, OUTPUT);
  pinMode(p9, OUTPUT);
  pinMode(p10, OUTPUT);
  pinMode(p11, OUTPUT);
  pinMode(p12, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  if (radio.available())
          {   radio.read(msg,sizeof(msg));
              x=msg[0];
              y=msg[1];
              Serial.print("Primer valor recibido es = ");
              Serial.println(x);
              Serial.print("Segundo valor recibido es = ");
              Serial.println(y);
              if(x>1000){
                digitalWrite(p2, HIGH);
              }else{
                digitalWrite(p2, LOW);
              }
              if(x>650){
                digitalWrite(p3, HIGH);
              }else{
                digitalWrite(p3, LOW);
              }
              if(x>300){
                digitalWrite(p4, HIGH);
              }else{
                digitalWrite(p4, LOW);
              }
              if(x>=50){
                digitalWrite(p5, HIGH);
              }else{
                digitalWrite(p5, LOW);
              }
              if(y>1000){
                digitalWrite(p2, HIGH);
              }else{
                digitalWrite(p2, LOW);
              }
              if(y>650){
                digitalWrite(p3, HIGH);
              }else{
                digitalWrite(p3, LOW);
              }
              if(y>300){
                digitalWrite(p4, HIGH);
              }else{
                digitalWrite(p4, LOW);
              }
              if(y>=50){
                digitalWrite(p5, HIGH);
              }else{
                digitalWrite(p5, LOW);
              }
              



              
              //print("Boton Rigth= ");
              //Serial.println(msg[2]);
              //Serial.print("Boton Up= ");
              //Serial.println(msg[3]);
              //Serial.print("Boton Down= ");
              //Serial.println(msg[4]);
              //Serial.print("Boton Left= ");
              //Serial.println(msg[5]);
          }
}

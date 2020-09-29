const byte PIN_BUTTON_SELECT = 22; 
const byte PIN_BUTTON_RIGHT = 23;
const byte PIN_BUTTON_UP = 24;
const byte PIN_BUTTON_DOWN = 25;
const byte PIN_BUTTON_LEFT = 26;

const int p1 = 2; 
const int p2 = 3;
const int p3 = 4;
const int p4 = 5;
const int p5 = 6;
const int p6 = 7;
const int p7 = 8;
const int p8 = 9;
const int p9 = 10;
const int p0 = 11;
const int pX = 12;

 int value1=0;
 int value2=0;
 int value3=0;
 int value4=0;
int valueXY=0;
const int botonXY=26;
const int joystickX = A0;
const int joystickY = A1;
int sensorValueX;
int sensorValueY;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(PIN_BUTTON_RIGHT, INPUT); 
  pinMode(p1, OUTPUT); 
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
  pinMode(p5, OUTPUT);
  pinMode(p6, OUTPUT);
  pinMode(p7, OUTPUT);
  pinMode(p8, OUTPUT);
  pinMode(p9, OUTPUT);
  pinMode(p0, OUTPUT);
  pinMode(pX, OUTPUT);
  digitalWrite(PIN_BUTTON_RIGHT, HIGH);
 
  pinMode(PIN_BUTTON_LEFT, INPUT);  
  digitalWrite(PIN_BUTTON_LEFT, HIGH);
 
  pinMode(PIN_BUTTON_UP, INPUT);  
  digitalWrite(PIN_BUTTON_UP, HIGH);
 
  pinMode(PIN_BUTTON_DOWN, INPUT);  
  digitalWrite(PIN_BUTTON_DOWN, HIGH);
 
  pinMode(PIN_BUTTON_SELECT, INPUT);  
  digitalWrite(PIN_BUTTON_SELECT, HIGH); 
 
}

void loop() {
  
sensorValueX = analogRead(joystickX);
sensorValueY = analogRead(joystickY);

Serial.println(sensorValueX);
Serial.println(sensorValueY);

if(sensorValueX>600){
  digitalWrite(p7, HIGH);
}else{
  digitalWrite(p7, LOW);
}
if(sensorValueX>700){
  digitalWrite(p8, HIGH);
}else{
  digitalWrite(p8, LOW);
}

if(sensorValueX>800){
  digitalWrite(p9, HIGH);
}else{
  digitalWrite(p9, LOW);
}

if(sensorValueX>900){
  digitalWrite(p0, HIGH);
}else{
  digitalWrite(p0, LOW);
}

if(sensorValueX>1000){
  digitalWrite(pX, HIGH);
}else{
  digitalWrite(pX, LOW);
}

if(sensorValueX>500 && sensorValueX<600){
  digitalWrite(p6, HIGH);
  digitalWrite(p5, HIGH);
}else{
  digitalWrite(p6, LOW);
  digitalWrite(p5, LOW);
}

if(sensorValueX<500){
  digitalWrite(p4, HIGH);
}else{
  digitalWrite(p4, LOW);
}

if(sensorValueX<350){
  digitalWrite(p3, HIGH);
}else{
  digitalWrite(p3, LOW);
}

if(sensorValueX<200){
  digitalWrite(p2, HIGH);
}else{
  digitalWrite(p2, LOW);
}

if(sensorValueX<100){
  digitalWrite(p1, HIGH);
}else{
  digitalWrite(p1, LOW);
}
 
  Serial.print("l:");
  Serial.print(digitalRead(PIN_BUTTON_LEFT));
  Serial.print(" ");
 
  Serial.print("r:");
  Serial.print(digitalRead(PIN_BUTTON_RIGHT));
  Serial.print(" ");
 
  Serial.print("u:");
  Serial.print(digitalRead(PIN_BUTTON_UP));
  Serial.print(" ");
 
  Serial.print("d:");
  Serial.print(digitalRead(PIN_BUTTON_DOWN));
  Serial.print(" ");
 
  Serial.print("s:");
  Serial.print(digitalRead(PIN_BUTTON_SELECT));
  Serial.print(" ");

  delay(500);
}
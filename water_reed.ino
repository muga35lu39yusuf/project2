#include <AFMotor.h>
#include<SoftwareSerial.h>
#define sensor 7;
void setup()
 { // put your setup code here, to run once:
 Serial.begin(57600);
 pinMode(sensor,INPUT_PULLUP);
 Serial.println("dddd");
 }

void loop()
 { // put your main code here, to run repeatedly:
 if(digitalRead(sensor)==1)
 {


 }
 }
 }

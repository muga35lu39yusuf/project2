int sensorPin = A0;
int sensorValue=0;
int percentValue=0;
int motor=5;
int upper;
int OPTION;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(sensorPin, INPUT);
pinMode(motor, OUTPUT);
Serial.println("1:Automatic");Serial.println("2: custom");
Serial.println("Enter OPTION");
 while(Serial.available()==0){};
   OPTION=Serial.parseInt();
switch(OPTION){ 
  case 1:
 Serial.println("Default irrigation on");
  break;
  case 2:
    Serial.println("Enter upper limit");
   while(Serial.available()==0){};
   upper=Serial.parseInt();
  break;
  default:
  Serial.println("Invalid input");
  break;
}


}
void motorstate(int state){
digitalWrite(5,state);
}
void loop() {
  // put your main code here, to run repeatedly:
if(OPTION==1){
 custom(); 
}
else if(OPTION==2){
  Autommatic();
}
  else{
    Serial.println("Invalid input");
  }
}
void Autommatic(){
  sensorValue=analogRead(sensorPin);
Serial.println("AnalogValue");
Serial.println(sensorValue);
delay(1000);
percentValue=map(sensorValue,1023,200,0,100);
//percentValue=100-(sensorValue*100);
Serial.println("percentValue");
Serial.print(percentValue);
Serial.println("%");
if(percentValue>40){
motorstate(400);
digitalWrite(5,LOW);
}
else{
motorstate(1000);
digitalWrite(5,HIGH);
}
delay(1000);
}


 void custom(){
  sensorValue=analogRead(sensorPin);
Serial.println("AnalogValue");
Serial.println(sensorValue);
delay(1000);
percentValue=map(sensorValue,1023,200,0,100);
//percentValue=100-(sensorValue*100);
Serial.println("percentValue");
Serial.print(percentValue);
Serial.println("%");
if(percentValue>upper){
motorstate(400);
digitalWrite(5,LOW);
}
else{
motorstate(1000);
digitalWrite(5,HIGH);
}
delay(1000);
 }

#include <dht.h>
#define DHT_datapin A0
dht DHT;
int data;
float temp,humidity;
void setup()
 { // put your setup code here, to run once:
 Serial.begin(57600);
 Serial.println("dddd");
 }

void loop()
 { // put your main code here, to run repeatedly:
 data=DHT.read11(DHT_datapin);
 temp=DHT.temperature;
 humidity=DHT.humidity;
 Serial.println("Temperature is"  );
 Serial.println(temp);
 Serial.println("humidity is is");
 Serial.println(humidity);
delay(1000);
//Serial.end();
 }

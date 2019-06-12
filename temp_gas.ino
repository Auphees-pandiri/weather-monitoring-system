#include <dht.h>
#define dht_apin A0 
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);
 dht DHT;
int airquality = 0;

 void setup(){
  mySerial.begin(9600);
 Serial.begin(9600);
  delay(500);
  delay(1000);
 }
 void loop(){
     DHT.read11(dht_apin);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    delay(5000);//Wait 5 seconds before accessing sensor again.
    int sensorValue = analogRead(A1);
  Serial.print("Air Quality = ");
  Serial.print(sensorValue);
  Serial.print("*PPM");
  Serial.println();

  mySerial.println("AT+CMGF=1");    
     delay(1000);  
     mySerial.println("AT+CMGS=\"+919182508705\"\r"); 
     delay(1000);

     mySerial.print("Current humidity = ");
    mySerial.print(DHT.humidity);
    mySerial.print("%  ");
    mySerial.print("temperature = ");
    mySerial.print(DHT.temperature); 
    mySerial.println("C  ");
    mySerial.print("Air Quality = ");
  mySerial.print(sensorValue);
  mySerial.print("*PPM");
  
         delay(100);
     mySerial.println((char)26); 
      delay(1000);
  
  delay(1000);
}

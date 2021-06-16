#include<Servo.h>
#include "DHT.h"

#define DHTTYPE DHT11 
#define dht_apin A1
Servo servo;
DHT dht(dht_apin, DHTTYPE);;
//int tempPin = A1;
int water = A2;
int angle=0;
int senseInput;
int reading;
float voltage,temperatureC,temperatureF;
int led1 = 8;
int led2 = 10;
int led3 = 11;
int buzzer = 7;
void setup() {
  Serial.begin(9600);
  Serial.println("DHTXxx test!");
  dht.begin();
  pinMode(water, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  servo.attach(9);
  servo.write(angle);
}

void loop() {

  
  Serial.print("Current Temperature:  ");
  

  
  Serial.print(dht.readTemperature());
  Serial.print("    Current Humidity:  ");
  Serial.print(dht.readHumidity());
  Serial.print("%     ");
  
  int value = analogRead(water);
  Serial.print(value);
  Serial.println();
  
  if(value > 150) {
    Serial.println("Very Heavy Rain");
    digitalWrite(led1, HIGH);
  
    
    digitalWrite(led2, HIGH);
    
    digitalWrite(led3, HIGH);
    for( angle = 0; angle <= 360; angle++)
    {
      servo.write(angle);
    //  digitalWrite(led3, HIGH);   
      delay(15);                
       
      // digitalWrite(led3, LOW);
    }
     for( angle = 360; angle >= 0; angle--)
    {
      servo.write(angle);
   

       // digitalWrite(led1, HIGH);                   
           delay(15);
      // digitalWrite(led1, LOW);
    }
    delay(1000);
    tone(buzzer, 1000);
   }else{
    Serial.println("Dry Weather");
   for( angle = 0; angle <= 360; angle++)
    {
      servo.write(angle);
      digitalWrite(led3, HIGH);   
      delay(15);                
       
       digitalWrite(led3, LOW);
    }
     for( angle = 360; angle >= 0;+ angle--)
    {
      servo.write(angle);
   

        digitalWrite(led1, HIGH);                   
           delay(15);
       digitalWrite(led1, LOW);
    }
     for( angle = 360; angle >= 0; angle--)
    {
    digitalWrite(led2, HIGH);
      delay(15);
      
      digitalWrite(led2, LOW);
    }
    
   }
    
  
    
}

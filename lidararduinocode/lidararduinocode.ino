// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// Rev.4 (06/2012)
// J.Rodrigo ( www.jrodrigo.net )
// more info at www.ardublog.com

#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();
#include <Servo.h>

Servo myservo;
int i=0;
void setup() {
  Serial.begin(9600); 
  myservo.attach(3); 
  myservo.write(0);
   if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
}

void loop()
{
 VL53L0X_RangingMeasurementData_t measure;

if(Serial.available()>0){
  char a=Serial.read();
  
  if(a =='a'){
   myservo.write(i);
   delay(15);
   lox.rangingTest(&measure, false);
   if (measure.RangeStatus != 4) {  // phase failures have incorrect data
     Serial.println((measure.RangeMilliMeter/10));
  } else {
    Serial.println(0);
  }
   i=i+1; 
  }
  else if(a =='b'){
     myservo.write(i);
     delay(15);
     lox.rangingTest(&measure, false);
     //delay(10);
  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
     Serial.println((measure.RangeMilliMeter/10));
  } else {
    Serial.println(0);
  }
   i=i-1; 
  }
  
}
  

  
}

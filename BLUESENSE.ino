
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(7,6);

int light=0;
int i;
int light2=1;
boolean lightToggle = false;
void setup() 
{
BTSerial.begin(9600);
Serial.begin(9600);
pinMode(10, INPUT);
light = digitalRead(10);

}

void loop() 
{
  if(true)
  {
    if(light != digitalRead(10))
    {
        light = digitalRead(10);
      
        //Serial.print("L1");
    }
    delay(500);
    if(light2 != digitalRead(10))
   {
        light2 = digitalRead(10);
        lightToggle = true;
       // Serial.print("L2");
    }  
    if(light == light2 && lightToggle)
    {  
      if(light == 1)
      {
        Serial.println(2, DEC);
        lightToggle = false;
      }
      else 
      {
        Serial.println(1, DEC);
        lightToggle = false;
      }
    }
  }
  if(BTSerial.available()){
    int iData = BTSerial.parseInt();
    if(iData == 0)
    {
      Serial.println(3, DEC);
     }
     else
     {
      Serial.println(4, DEC);
     }
  }
} 

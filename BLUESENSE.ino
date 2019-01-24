
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(7,6);

int light=0;
int i;

void setup() 
{
BTSerial.begin(9600);
Serial.begin(9600);
pinMode(10, INPUT);
light = digitalRead(10);
}

void loop() 
{
  if(light != digitalRead(10))
  {
    light = digitalRead(10);
    if(light == 1)
    {
      Serial.println(1, DEC);
    }
    else
    {
      Serial.println(2, DEC);
    }
  }
  if(BTSerial.available()){
    int iData = BTSerial.parseInt();
    if(iData == 1)
    {
      Serial.println(3, DEC);
     }
     else
     {
      Serial.println(4, DEC);
     }
  }
} 

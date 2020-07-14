#include <Wire.h>

int distance = 0;               
byte high, low = 0;            
int shift = 0;                   

#define ADDRESS       0x80 >> 1  
#define DISTANCE_REG  0x5E
#define SHIFT         0x35

void setup()
{
  // Start comms
  Wire.begin();
  Serial.begin(9600);
  
  delay(50);  
  Wire.beginTransmission(ADDRESS);    
  Wire.write(SHIFT);
  Wire.endTransmission();
  
  Wire.requestFrom(ADDRESS, 1);
  while(Wire.available() == 0);
  shift = Wire.read();
}

void loop()
{
    Wire.beginTransmission(ADDRESS);
  Wire.write(DISTANCE_REG);
  Wire.endTransmission();
  
  Wire.requestFrom(ADDRESS, 2);
  
  while(Wire.available() < 2);
  
  high = Wire.read();
  low = Wire.read();
  
  distance = (high * 16 + low)/16/(int)pow(2,shift); // Calculate the range in CM
  
  Serial.print("Distance is ");
  Serial.print(distance);
  Serial.println("CM");
  
  delay(50);
}

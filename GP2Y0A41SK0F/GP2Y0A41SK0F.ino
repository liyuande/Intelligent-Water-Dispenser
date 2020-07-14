[mw_shl_code=cpp,true]
#include <math.h>
float val=0;  
char GP2D12;
  
char a,b;
  
void setup()
  
{
  
   Serial.begin(9600); //
  
}
  
void loop()
  
{
  
   int val;
  
   GP2D12=read_gp2d12_range();
  
   delay(500);
  
}
  
  
float read_gp2d12_range()
  
{
  
   float tmp;
  
   tmp = analogRead(A0);
  
   tmp=tmp*4/1024;   //4为VREF基准：实际值
  
   tmp=8.7328*pow(tmp,-0.912)+0.25;    //0.25是调整值，根据测距情况自行添加相应的值
  
   Serial.println(tmp);
  
   return tmp;
  
}
[/mw_shl_code]

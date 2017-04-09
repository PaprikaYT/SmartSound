int16_t adc0;
int mini,maxi;
int delta =0;
int g=60;
 int longtime=0;
 int longtime2;
#define samples  200

#include <Wire.h>
void setup(void) 
{
  Serial.begin(9600);
  Wire.begin(8); 
  Wire.onRequest(requestEvent);
}

void requestEvent() 
{
  Wire.write(longtime2);
}
void loop(void) 
{
 longtime=0;
  for(int x=0;x<samples;x++)
    {
      int all=0;
      int allmax=0;
      for(int anzahl=0;anzahl<5;anzahl++)
        {
          mini=0;
          maxi=0;
          for(int x=0;x<10;x++)
            {
              adc0 = analogRead(A0);
              if(adc0<mini)
                {
                  mini=adc0;
                }
              if(adc0>maxi)
                {
                  maxi=adc0;
                }
            }
          delta=maxi-mini;
          delta-=512;
          if(delta<0)
          {
            delta*-1;
          }
          all+=delta;     
      }
  all/=5;
    longtime+=delta;
  }
  longtime/=samples;
  longtime2=longtime;
  Serial.println(longtime);
}

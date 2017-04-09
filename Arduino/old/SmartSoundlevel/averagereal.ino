int averageSound(int times)
{
      int audio=0;
      for(int anzahl=0;anzahl<times;anzahl++)
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
          delta-=733;
          audio+=delta;
      } 
    audio/=times;
    int x=map(audio,0,250,0,100);
    Device.Send(String(x),soundlevel);
    if(audio<0){audio=0;}
    return audio;
}

float beerprice(float start,int count)
{
  unsigned long deltaBeer=0;
  float price;
  for(int x=0;x<count;x++)
  {
    audioReal=averageSound(5);
    colorSound(audioReal);
    deltaBeer+=audioReal;
    delay(cicletime);
  }
  deltaBeer/=count;
  if(deltaBeer>=0&&deltaBeer<=255*0.25)
  {
    price= start;
  }
  if(deltaBeer>255*0.25&&deltaBeer<=255*0.5)
  {
    price= start+0.2;
  }
  if(deltaBeer>255*0.5&&deltaBeer<=255*0.75)
  {
    price= start+0.4;
  }
  if(deltaBeer>255*0.75&&deltaBeer<=255)
  {
    price= start+0.6;
  }
  return price;
}
  

void animationstart()
{
   for(int x=0;x<pixelnr;x++)
 {
  
  pixels.setPixelColor(x, pixels.Color(255,50,0));
  pixels.show();
  delay(25);
 }
}
 void animationend()
 {
 for(int x =pixelnr;x>=0;x--)
 {
  
  pixels.setPixelColor(x, pixels.Color(0,0,0));
  pixels.show();
  delay(25);
 }
}
void wholering(int red,int green,int blue)
{
  for(int x=0;x<=pixelnr;x++)
  {
    pixels.setPixelColor(x, pixels.Color(red,green,blue));
    pixels.show();
  }
}

void twoways(int a,int b,int c)
{
    for(int x=0;x<=60;x++)
  {
      pixels.setPixelColor(x, pixels.Color(a,b,c));
      pixels.setPixelColor(60-x, pixels.Color(0,0,0));
      pixels.show();
      delay(20);
  }
}

void callback(char* topic, byte* payload, unsigned int length) 
{ 
  String msgString; 
  {                                                      
  char message_buff[length + 1];                       
  strncpy(message_buff, (char*)payload, length);      
  message_buff[length] = '\0';                  
      
  msgString = String(message_buff);
  msgString.toLowerCase();            
  }
  int* idOut = NULL;
  {                                                       
      int pinNr = Device.GetPinNr(topic, strlen(topic));
    
     
  }
  if(idOut != NULL)                            
    Device.Send(msgString, *idOut);    
}

void colorSound(int x,int led)
{
    if(x==1)
    {
      pixels.setPixelColor(led, pixels.Color(color1));
      pixels.show();
    }
    else if(x==2)
    {
      pixels.setPixelColor(led, pixels.Color(color2));
      pixels.show();
    }
    else if(x==3)
    {
      pixels.setPixelColor(led, pixels.Color(color3));
      pixels.show();
    }
    else if(x==4)
    {
      pixels.setPixelColor(led, pixels.Color(color4));
      pixels.show();
    }
  }



void blinkring(int number,int red,int green,int blue)
{
  for(int x=0;x<number;x++)
  {
    for(int x =0;x<24;x++)
 {
  
  pixels.setPixelColor(x, pixels.Color(red,green,blue));
  pixels.show();
 }
  delay(100);
  for(int x =0;x<24;x++)
 {
  
  pixels.setPixelColor(x, pixels.Color(0,0,0));
  pixels.show();
 }
 delay(100);
}
}


void animationstart()
{
   for(int x=0;x<24;x++)
 {
  
  pixels.setPixelColor(x, pixels.Color(255,50,0));
  pixels.show();
  delay(25);
 }
}
 void animationend()
 {
 for(int x =24;x>=0;x--)
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
void ringoff()
{
  for(int x=0;x<=pixelnr;x++)
  {
    pixels.setPixelColor(x, pixels.Color(0,0,0));
    pixels.show();
  }
}

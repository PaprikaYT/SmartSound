void blinkring(int number,int red,int green,int blue)
{
  for(int x=0;x<number;x++)
  {
    for(int x =0;x<pixelnr;x++)
 {
  
  pixels.setPixelColor(x, pixels.Color(red,green,blue));
  pixels.show();
 }
  delay(100);
  for(int x =0;x<pixelnr;x++)
 {
  
  pixels.setPixelColor(x, pixels.Color(0,0,0));
  pixels.show();
 }
 delay(100);
}
}


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
  }
  pixels.show();
}
void ringoff()
{
  for(int x=0;x<=pixelnr;x++)
  {
    pixels.setPixelColor(x, pixels.Color(0,0,0));
    pixels.show();
  }
}

void animation1(int red,int green,int blue)
{
  for(int x =0;x<=pixelnr;x++)
  {
    pixels.setPixelColor(x,pixels.Color(red,green,blue));
    pixels.show();
    delay(25);
  }
  for(int x=0;x<=pixelnr;x++)
  {
    pixels.setPixelColor(x,pixels.Color(0,0,0));
     pixels.show();
     delay(25);
  }
  
}

void animation2()
{
  int b,c,d;
  int color8=(b,c,d);
  for(int x =0;x<=60;x++)
  {
    pixels.setPixelColor(x,pixels.Color(color8));
    pixels.show();
  }
}
void randomstuff()
{
int red=random(0,255);
 int green=random(0,255);
int  blue=random(0,255); 
for(int x =0;x<=pixelnr;x++)
  {
    pixels.setPixelColor(x,pixels.Color(red,green,blue));
    pixels.show();
    delay(25);
  }
}

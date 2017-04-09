void game(int lev)
{
  if(lev>=0&&lev<10)
  {
    ringone(lev);
    off2();
    off3();
    off4();
    off5();
  }
  if(lev>=10&&lev<20)
  {
    on1();
    ringtwo(lev);
    off3();
    off4();
    off5();
  }
  if(lev>=20&&lev<30)
  {
    on1();
    on2();
    ringthree(lev);
    off4();
    off5();
  }
  if(lev>=30&&lev<40)
  {
    on1();
    on2();
    on3();
    ringfour(lev);
    off5();
  }
  if(lev>=40&&lev<50)
  {
    on1();
    on2();
    on3();
    on4();
    ringfive(lev);
  }
  if(lev==50)
  {
    on1();
    on2();
    on3();
    on4();
    on5();
  }
}



void ringone(int pix)
{
  int leds=pix*2.4;
  for(int x=0;x<=leds;x++)
  {
    ring1.setPixelColor(x, ring1.Color(color1));
    ring1.show();
  }
  for(int x=leds;x<=NUMPIXELS;x++)
  {
    ring1.setPixelColor(x, ring1.Color(zero));
    ring1.show();
  }
}

void ringtwo(int pix)
{
  int leds=(pix-10)*2.4;
  for(int x=0;x<=leds;x++)
  {
    ring2.setPixelColor(x, ring2.Color(color1));
    ring2.show();
  }
  for(int x=leds;x<=NUMPIXELS;x++)
  {
    ring2.setPixelColor(x, ring2.Color(zero));
    ring2.show();
  }
}
void ringthree(int pix)
{
  int leds=(pix-20)*2.4;
  for(int x=0;x<=leds;x++)
  {
    ring3.setPixelColor(x, ring3.Color(color1));
    ring3.show();
  }
  for(int x=leds;x<=NUMPIXELS;x++)
  {
    ring3.setPixelColor(x, ring3.Color(zero));
    ring3.show();
  }
}

void ringfour(int pix)
{
  int leds=(pix-30)*2.4;
  for(int x=0;x<=leds;x++)
  {
    ring4.setPixelColor(x, ring4.Color(color1));
    ring4.show();
  }
  for(int x=leds;x<=NUMPIXELS;x++)
  {
    ring4.setPixelColor(x, ring4.Color(zero));
    ring4.show();
  }
}

void ringfive(int pix)
{
  int leds=(pix-40)*2.4;
  for(int x=0;x<=leds;x++)
  {
    ring5.setPixelColor(x, ring5.Color(color1));
    ring5.show();
  }
  for(int x=leds;x<=NUMPIXELS;x++)
  {
    ring5.setPixelColor(x, ring5.Color(zero));
    ring5.show();
  }
}


void off1()
{  
  for(int x=0;x<=NUMPIXELS;x++)
  {
    ring1.setPixelColor(x, ring1.Color(zero));
    ring1.show();
  }
}

void off2()
{  
  for(int x=0;x<=NUMPIXELS;x++)
  {
    ring2.setPixelColor(x, ring2.Color(zero));
    ring2.show();
  }
}

void off3()
{  
  for(int x=0;x<=NUMPIXELS;x++)
  {
    ring3.setPixelColor(x, ring3.Color(zero));
    ring3.show();
  }
}

void off4()
{  
  for(int x=0;x<=NUMPIXELS;x++)
  {
    ring4.setPixelColor(x, ring4.Color(zero));
    ring4.show();
  }
}

void off5()
{  
  for(int x=0;x<=NUMPIXELS;x++)
  {
    ring5.setPixelColor(x, ring5.Color(zero));
    ring5.show();
  }
}


void on1()
{  
  for(int x=0;x<=NUMPIXELS;x++)
  {
    ring1.setPixelColor(x, ring1.Color(color));
    ring1.show();
  }
}

void on2()
{  
  for(int x=0;x<=NUMPIXELS;x++)
  {
    ring2.setPixelColor(x, ring2.Color(color));
    ring2.show();
  }
}

void on3()
{  
  for(int x=0;x<=NUMPIXELS;x++)
  {
    ring3.setPixelColor(x, ring3.Color(color));
    ring3.show();
  }
}

void on4()
{  
  for(int x=0;x<=NUMPIXELS;x++)
  {
    ring4.setPixelColor(x, ring4.Color(color));
    ring4.show();
  }
}

void on5()
{  
  for(int x=0;x<=NUMPIXELS;x++)
  {
    ring5.setPixelColor(x, ring5.Color(color));
    ring5.show();
  }
}




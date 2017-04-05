void colorSound(int input)
{
  int y=map(input,0,250,0,pixelnr);
  for(int x=0;x<=y;x++)
  {
    if(x>=0&&x<=pixelnr*0.25)
    {
      pixels.setPixelColor(x, pixels.Color(0,255,0));
      pixels.show();
    }
    else if(x>pixelnr*0.25&&x<=pixelnr*0.5)
    {
      pixels.setPixelColor(x, pixels.Color(255,60,0));
      pixels.show();
    }
    else if(x>pixelnr*0.5&&x<=pixelnr*0.75)
    {
      pixels.setPixelColor(x, pixels.Color(255,0,0));
      pixels.show();
    }
    else if(x>pixelnr*0.75&&x<=pixelnr)
    {
      pixels.setPixelColor(x, pixels.Color(100,0,255));
      pixels.show();
    }
    else if(x>pixelnr)
    {
      wholering(255,0,0);
    }
  }
  for(int x=pixelnr;x>y;x--)
  {
      pixels.setPixelColor(x, pixels.Color(0,0,0));
      pixels.show();
  }
}


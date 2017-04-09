
void runforever()
{
  int longtime;
  int all = 0;
  for (int x = 0; x <= 60; x++)
  {
    Wire.requestFrom(8, 1);    // request 6 bytes from slave device #8
    while (Wire.available())
    {
      audioReal = Wire.read();
      if(audioReal<0)
      {
        audioReal=audioReal*-1;
      }
    }   
      delay(500);
      Serial.println(audioReal);
      int maped = map(audioReal, 0, 70, 1, 4);
      if(audioReal>70)
      {
        maped=4;
      }
      colorSound(maped, x);
      Device.Send(String(audioReal), soundlevel);
      all += maped;
  }
  longtime = all / 60;
  if (longtime == 1)
  {
    twoways(color1);
    wholering(0, 0, 0);
    unlock += 2;
  }
  if (longtime == 2)
  {
    twoways(color2);
    wholering(0, 0, 0);
    unlock++;
  }
  if (longtime == 3)
  {
    twoways(color4);
    wholering(0, 0, 0);
    unlock--;
  }
  if (longtime >= 3)
  {
    twoways(color4);
    wholering(0, 0, 0);
    unlock -= 2;
  }
  if(unlock>=50)
  {
    unlock=50;
  }
  if(unlock<=0)
  {
    unlock=0;
  }
  Device.Send(String(unlock), beer);
}


#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Adafruit_HTU21DF.h"
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
int level;
Adafruit_HTU21DF htu = Adafruit_HTU21DF();
void setup() {
  // put your setup code here, to run once:
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  Serial1.begin(9600);
  htu.begin();
}

void loop() {
  
  float x;
  float y;
    x=htu.readTemperature();
    y=htu.readHumidity();
  while(Serial1.available())
  {
    String string="";
    string+=x;
    string+=",";
    string+=y;
    String IncomingData  = Serial1.readStringUntil('$');
    level=IncomingData.toInt();
    Serial1.print(string);  
    }
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Temperature: ");
  display.print(x-2.0);
  display.println(" C");
  display.print("Humidity: ");
  display.print(y);
  display.println(" %");
  display.print("Level: ");
  display.println(level);
  display.display();
  display.clearDisplay();
}

// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN1            3
#define PIN2            4
#define PIN3            6
#define PIN4            8
#define PIN5            9
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      24
#define color 20,20,20
#define color1 0,40,0
#define zero 0,0,0
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel ring1 = Adafruit_NeoPixel(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring3 = Adafruit_NeoPixel(NUMPIXELS, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring4 = Adafruit_NeoPixel(NUMPIXELS, PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ring5 = Adafruit_NeoPixel(NUMPIXELS, PIN5, NEO_GRB + NEO_KHZ800);
int delayval = 25; // delay for half a second

void setup() {
  ring1.begin();
  ring2.begin();
  ring3.begin();
  ring4.begin();
  ring5.begin();
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop() {
  int level;
  while(Serial1.available())
  {
    String IncomingData  = Serial1.readStringUntil('$');
    level=IncomingData.toInt();
    Serial.println(level);
    }
  game(level);    
    
}




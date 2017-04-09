#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ATT_IOT.h>                           
#include <SPI.h>                             
#define httpServer "api.allThingsTalk.io"                                  
#define mqttServer httpServer 
#define cicletime 10
#define numberofCicles 1000
#define brightness 1
#define pricetoStart 2.50
#define color1 0*brightness,255*brightness,0*brightness
#define color2 255*brightness,60*brightness,0*brightness
#define color3 255*brightness,0*brightness,0*brightness
#define color4 0*brightness,0*brightness,255*brightness
 
int pixelnr=60;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(pixelnr, D6, NEO_GRB + NEO_KHZ800); 
char deviceId[] = "2nBGwv34DG7WMmxaznPBjKtk"; 
char clientId[] = "PaprikaYT_gcHaggvf";
char clientKey[] = "G0sFl3FM";
const char* ssid     = "Makerversity";
const char* password = "Mak3rvers1t!";
ATTDevice Device(deviceId, clientId, clientKey);            
int audioReal;                                             
int beer= 0;
int mini,maxi,adc0,delta;
int soundlevel = 1;
void callback(char* topic, byte* payload, unsigned int length);
WiFiClient ethClient;
PubSubClient pubSub(mqttServer, 1883, callback,ethClient);  

void setup()
{   
  pixels.begin(); 
  Serial.begin(9600);  
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    animationstart();
  }
  delay(1000);
  while(!Device.Connect(&ethClient, httpServer))     
  Device.AddAsset(beer,"Beerprice","Beerprice",false,"number");
  Device.AddAsset(soundlevel,"Realtime Soundlevel","Realtime Soundlevel",false,"integer");
  while(!Device.Subscribe(pubSub)) 
  {
  }                            
  animationend();
  ESP.wdtEnable(1000);                                                   
}
                    
void loop()
{
  ESP.wdtFeed();
  float finalprice=beerprice(pricetoStart,numberofCicles);
  Device.Send(String(finalprice),beer);
}





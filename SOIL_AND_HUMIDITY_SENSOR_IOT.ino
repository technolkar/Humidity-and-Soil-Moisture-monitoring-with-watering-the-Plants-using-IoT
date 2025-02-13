#define BLYNK_TEMPLATE_ID "TMPLZAjilV08"
#define BLYNK_TEMPLATE_NAME "AMRAT"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

#include <BlynkSimpleEsp8266.h>
#define DHTPIN 2 //d4
#define DHTTYPE DHT11
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define SCREEN_ADDRESS 0x3C
#define mlevelIN 0

boolean state = false;

DHT dht(DHTPIN, DHTTYPE);

char auth[] = "xIYRLw6_oTeyFx75ZzWpBcoJy0qubOFV";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "AMRAT123";
char pass[] = "techo123";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(mlevelIN,INPUT);
  dht.begin();
}

void loop() {
  Blynk.run();
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  int m = analogRead(mlevelIN);
  
  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("Temperature:");
  Serial.println(t);
  Serial.print("Moisture Level: ");
  Serial.println(m);
  Blynk.virtualWrite(V10,h);
  Blynk.virtualWrite(V11,t);
  Blynk.virtualWrite(V12,m);
  if(m<=1000)
    Blynk.setProperty(V12,"color","#00FF00");
  else
    Blynk.setProperty(V12,"color","#FF0000");  

}

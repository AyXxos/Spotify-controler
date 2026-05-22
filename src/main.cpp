#include <Arduino.h>
#include <WiFi.h>
#include "SpotifyEsp32.h"
#include "secrets.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void connect_to_wifi();

Spotify sp(CLIENT_ID, CLIENT_SECRET, REFRESH_TOKEN, 3);
String track_name;
void setup() {
 Serial.begin(9600);
 connect_to_wifi();

 sp.begin();
  track_name = sp.current_track_name();

   if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
    display.clearDisplay();
    display.display();
   
}

void loop() {
 String new_track_name = sp.current_track_name();
    Serial.printf("%s\n", new_track_name.c_str());

if (track_name == new_track_name) {
        // Track hasn't changed
    } else {
        // Track has changed
        track_name = new_track_name;
        display.clearDisplay();
    }

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    display.printf("%s", track_name.c_str());
    display.display();

}

void connect_to_wifi() {
 WiFi.begin(SSID, PASSWORD);
 Serial.print("Connecting to WiFi...");
 while (WiFi.status() != WL_CONNECTED) {
     delay(1000);
     Serial.print(".");
 }
 Serial.println("\nConnected to WiFi!");
}
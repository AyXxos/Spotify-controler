#include <Arduino.h>
#include <WiFi.h>
#include "SpotifyEsp32.h"
#include "secrets.h"

void connect_to_wifi();

Spotify sp(CLIENT_ID, CLIENT_SECRET, REFRESH_TOKEN, 3);

void setup() {
 Serial.begin(9600);
 connect_to_wifi();

 sp.begin();
}

void loop() {
 String track_name = sp.current_track_name();
    Serial.printf("%s\n", track_name.c_str());
    delay(5000);


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
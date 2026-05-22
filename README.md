ESP32 Spotify Controller
========================

Overview
--------
This project runs on an ESP32 and talks to the Spotify Web API. It uses a custom
Spotify client class to authenticate and fetch playback data (for example, the
current track name).

Requirements
------------
- ESP32 Dev Module
- PlatformIO (VS Code extension)
- A Spotify Developer app (Client ID and Client Secret)
- Wi-Fi connection

Setup
-----
1) Create a Spotify app at https://developer.spotify.com/dashboard
2) Add this Redirect URI in the app settings:
   https://spotifyesp32.vercel.app/api/spotify/callback
3) Build and upload once to get the authorization URL on the serial monitor.
4) Open the URL, authorize, and capture the refresh token from the callback.

Configuration
-------------
Create a header named [src/secrets.h](src/secrets.h) and define:
- SSID / PASSWORD
- CLIENT_ID / CLIENT_SECRET
- REFRESH_TOKEN

Example (do not commit real values):
```cpp
#pragma once

#define SSID "your_wifi"
#define PASSWORD "your_password"
#define CLIENT_ID "your_client_id"
#define CLIENT_SECRET "your_client_secret"
#define REFRESH_TOKEN "your_refresh_token"
```

Notes
-----
- Keep your credentials private and avoid committing [src/secrets.h](src/secrets.h).
- The serial monitor speed must match Serial.begin (currently 9600).
- The current sketch uses the refresh token path, so no interactive auth is needed.
- TLS can fail if the ESP32 time is not set. If you see SSL errors, sync time
  before calling Spotify APIs.

Build and Upload
----------------
- Use the PlatformIO task: Upload and Monitor

Troubleshooting
---------------
- Gibberish on serial: wrong monitor speed.
- "Something went wrong": missing auth or invalid refresh token.
- SSL errors: time not set, or unstable network.

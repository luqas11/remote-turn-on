# Firmware

This ESP8266 sketch connects the board to the WiFi network and a Blynk Cloud project using the credentials defined in the `config.h` file. It listens to a Virtual Pin named `V0`, which must be configured in the Blynk console as an integer datastream with range `0` to `1`. When the value of the datastream changes, the `BLYNK_WRITE` listener will be called. If the value is `0`, the LED will be turned off, and if the value is `1`, the LED will be turned on and a WoL magick packet will be sent. The Virtual Pin value change is triggered from the mobile app.

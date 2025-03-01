#include <ESP8266WiFi.h>
#include "config.h"
#include <BlynkSimpleEsp8266.h>
#include <WiFiUdp.h>
#include <WakeOnLan.h>

// Pin of the LED to be controlled
int LED_PIN = 2;

WiFiUDP UDP;
WakeOnLan WOL(UDP);

// Listener to the Blynk Virtual Pin V0
BLYNK_WRITE(V0)
{
  // Get the Virtual Pin current value
  int value = param.asInt();

  // Set the LED to the status of the Virtual Pin
  digitalWrite(LED_PIN, !value);

  // If the Virtual Pin is HIGH, send the Wake On LAN magic packet to the given MAC address
  if (value){
    WOL.sendMagicPacket(MAC_ADDRESS);
  }
}

void setup()
{
  // Initialize the LED turned off
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  // Connect the board to the Blynk Cloud
  Blynk.begin(BLYNK_AUTH_TOKEN, SSID, PASSWORD);
}

void loop()
{
  // Run the Blynk listeners
  Blynk.run();
}

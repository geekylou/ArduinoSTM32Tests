#include "usb_serial.h"
#include "libmaple/usb_cdcacm.h"
/*
  Blink powersave test
  Modified Blink sketch to test USB suspend functionality.  This will blink when connected and show
  a continous light (or no light at all on maple mini) when disconnected if suspend works correctly.
 */

#define LED PC13 // Set to PC13 on Bluepill and 33 on Maple mini

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED, (usb_is_connected(USBLIB) && usb_is_configured(USBLIB)));
  delay(1000);              // wait for a second
  digitalWrite(LED, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
}

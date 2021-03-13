#include <Arduino.h>
#include "display.h"

Display display;


void setup(void) {
  Serial.begin(115200);
  display.begin();
  display.setTitle("myApp");
  display.setFoot("192.168.0.0");
}

void loop() {
  display.update();
  delay(4000);
}

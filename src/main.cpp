#include <Arduino.h>
#include "display.h"


Display display;

void setup(void) {
  Serial.begin(115200);
  display.begin();
  display.setTitle("myApp");
  display.setFoot("192.168.0.0");
  display.update();
}

int value = 0;

void loop() {
  value +=5;
  if (value > 115)
    value = 0;
  display.plotLinear("X1", 60, 40, value);
  delay(100);
}

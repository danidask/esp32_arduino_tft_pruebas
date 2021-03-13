#include <Arduino.h>
#include "pantalla.h"

Pantalla pantalla;


void setup(void) {
  Serial.begin(115200);
  pantalla.begin();
}

void loop() {
  pantalla.update();
  delay(4000);
}

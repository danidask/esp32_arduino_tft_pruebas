#include <Arduino.h>
#include "SPI.h"
#include "TFT_eSPI.h"
#include "Free_Fonts.h" // Include the header file attached to this sketch
// #include "display.cpp"

// Use hardware SPI
TFT_eSPI tft = TFT_eSPI();

unsigned long drawTime = 0;

class Pantalla{
  public:
    String texto;
    void update(){
      Serial.println(texto);
      int xpos =  0;
      int ypos = 40;
      // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
      // Select different fonts to draw on screen using the print class
      // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

      header("Using print() method", TFT_NAVY);

      // For comaptibility with Adafruit_GFX library the text background is not plotted when using the print class
      // even if we specify it.
      tft.setTextColor(TFT_YELLOW);
      tft.setCursor(xpos, ypos);    // Set cursor near top left corner of screen

      tft.setFreeFont(TT1);     // Select the orginal small TomThumb font
      tft.println();             // Move cursor down a line
      tft.print("The really tiny TomThumb font");    // Print the font name onto the TFT screen
      tft.println();
      tft.println();

      tft.setFreeFont(FSB9);   // Select Free Serif 9 point font, could use:
      // tft.setFreeFont(&FreeSerif9pt7b);
      tft.println();          // Free fonts plot with the baseline (imaginary line the letter A would sit on)
      // as the datum, so we must move the cursor down a line from the 0,0 position
      tft.print("Serif Bold 9pt");  // Print the font name onto the TFT screen

      tft.setFreeFont(FSB12);       // Select Free Serif 12 point font
      tft.println();                // Move cursor down a line
      tft.print("Serif Bold 12pt"); // Print the font name onto the TFT screen

      tft.setFreeFont(FSB18);       // Select Free Serif 12 point font
      tft.println();                // Move cursor down a line
      tft.print("Serif Bold 18pt"); // Print the font name onto the TFT screen

      tft.setFreeFont(FSB24);       // Select Free Serif 24 point font
      tft.println();                // Move cursor down a line
      tft.print("Serif Bold 24pt"); // Print the font name onto the TFT screen

    }
  private:
    // Print the header for a display screen
    void header(const char *string, uint16_t color)
    {
      tft.fillScreen(color);
      tft.setTextSize(1);
      tft.setTextColor(TFT_MAGENTA, TFT_BLUE);
      tft.fillRect(0, 0, 320, 30, TFT_BLUE);
      tft.setTextDatum(TC_DATUM);
      tft.drawString(string, 160, 2, 4); // Font 4 for fast drawing with background
    }

    // Draw a + mark centred on x,y
    void drawDatumMarker(int x, int y)
    {
      tft.drawLine(x - 5, y, x + 5, y, TFT_GREEN);
      tft.drawLine(x, y - 5, x, y + 5, TFT_GREEN);
    }

};

Pantalla pantalla;


void setup(void) {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(1);
}

void tonteria(){
  static unsigned long nextTime = 0;
  if (millis()<nextTime)
    return;
  nextTime = millis() + 1000;
  // Serial.println("tonteria");
  pantalla.texto = "texto de prueba";
  pantalla.update();
}

void loop() {
  tonteria();
  delay(4000);
}



// There follows a crude way of flagging that this example sketch needs fonts which
// have not been enbabled in the User_Setup.h file inside the TFT_HX8357 library.
//
// These lines produce errors during compile time if settings in User_Setup are not correct
//
// The error will be "does not name a type" but ignore this and read the text between ''
// it will indicate which font or feature needs to be enabled
//
// Either delete all the following lines if you do not want warnings, or change the lines
// to suit your sketch modifications.

#ifndef LOAD_GLCD
//ERROR_Please_enable_LOAD_GLCD_in_User_Setup
#endif

#ifndef LOAD_FONT2
//ERROR_Please_enable_LOAD_FONT2_in_User_Setup!
#endif

#ifndef LOAD_FONT4
//ERROR_Please_enable_LOAD_FONT4_in_User_Setup!
#endif

#ifndef LOAD_FONT6
//ERROR_Please_enable_LOAD_FONT6_in_User_Setup!
#endif

#ifndef LOAD_FONT7
//ERROR_Please_enable_LOAD_FONT7_in_User_Setup!
#endif

#ifndef LOAD_FONT8
//ERROR_Please_enable_LOAD_FONT8_in_User_Setup!
#endif

#ifndef LOAD_GFXFF
ERROR_Please_enable_LOAD_GFXFF_in_User_Setup!
#endif

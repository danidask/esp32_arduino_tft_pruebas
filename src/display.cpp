#include <Arduino.h>
#include "SPI.h"
#include "TFT_eSPI.h"
#include "Free_Fonts.h" // Include the header file attached to this sketch
#include "display.h"

// Use hardware SPI
TFT_eSPI tft = TFT_eSPI();

void Display::begin(){
    tft.begin();
    tft.setRotation(1);
}

void Display::update(){
    // No permitir actualizaciones de menos de x ms
    if (millis() < lastUpdate + 100)
        return;
    lastUpdate = millis();

    tft.fillScreen(TFT_NAVY);
    drawHeader(titleTxt);

    tft.setTextColor(TFT_YELLOW);
    tft.setCursor(0, 80); // Set cursor near top left corner of screen

    tft.setFreeFont(FSB18);       // Select Free Serif 12 point font
    tft.setTextDatum(TC_DATUM); // Centre text on x,y position
    int16_t xpos = tft.width() / 2; // Half the screen width
    int16_t ypos = 50;
    tft.drawString("Message", xpos, ypos, GFXFF);  // Draw the text string in the selected GFX free font
    ypos += tft.fontHeight(GFXFF);                      // Get the font height and move ypos down
    tft.drawString(String(millis()).c_str(), xpos, ypos, GFXFF);
    drawFoot();
}

void Display::fontTest(){
    int xpos = 0;
    int ypos = 40;
    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    // Select different fonts to draw on screen using the print class
    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    tft.fillScreen(TFT_NAVY);
    drawHeader("Using print() method");

    // For comaptibility with Adafruit_GFX library the text background is not plotted when using the print class
    // even if we specify it.
    tft.setTextColor(TFT_YELLOW);
    tft.setCursor(xpos, ypos); // Set cursor near top left corner of screen

    tft.setFreeFont(TT1);                       // Select the orginal small TomThumb font
    tft.println();                              // Move cursor down a line
    tft.print("The really tiny TomThumb font"); // Print the font name onto the TFT screen
    tft.println();
    tft.println();

    tft.setFreeFont(FSB9); // Select Free Serif 9 point font, could use:
    // tft.setFreeFont(&FreeSerif9pt7b);
    tft.println(); // Free fonts plot with the baseline (imaginary line the letter A would sit on)
    // as the datum, so we must move the cursor down a line from the 0,0 position
    tft.print("Serif Bold 9pt"); // Print the font name onto the TFT screen

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

// Print the header for a display screen
void Display::drawHeader(const char *string){
    tft.setTextSize(1);
    tft.setTextColor(TFT_MAGENTA, TFT_BLUE);
    tft.fillRect(0, 0, 320, 30, TFT_BLUE);
    tft.setTextDatum(TC_DATUM);
    tft.drawString(string, 160, 2, 4); // Font 4 for fast drawing with background
}

void Display::drawFoot(){
    tft.setTextSize(1);
    tft.setTextColor(TFT_MAGENTA, TFT_BLUE);
    tft.fillRect(0, 216, 320, 240, TFT_BLUE);
    tft.setTextDatum(CC_DATUM);
    tft.drawString(footTxt, 160, 230, 4); // Font 4 for fast drawing with background
}

// Draw a + mark centred on x,y
void Display::drawDatumMarker(int x, int y){
    tft.drawLine(x - 5, y, x + 5, y, TFT_GREEN);
    tft.drawLine(x, y - 5, x, y + 5, TFT_GREEN);
}

void Display::setTitle(const String& text){
    strcpy(titleTxt, text.c_str());
}

void Display::setTitle(const char * text){
    strcpy(titleTxt, text);
}

void Display::setFoot(const String& text){
    strcpy(footTxt, text.c_str());
}

void Display::setFoot(const char * text){
    strcpy(footTxt, text);
}

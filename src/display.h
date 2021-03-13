#pragma once
#include <Arduino.h>

class Display{
public:
    char titleTxt[50] = "App";
    char footTxt[40] = "0.0.0.0";

    void begin();
    void update();
    void fontTest();
    void setTitle(const String& text);
    void setTitle(const char * text);
    void setFoot(const String& text);
    void setFoot(const char * text);

private:
    unsigned long lastUpdate = 0;

    void drawHeader(const char *string);
    void drawFoot();
    void drawDatumMarker(int x, int y);
};

// TODO remove not used fonts here and in platformio.ini
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
ERROR_Please_enable_LOAD_GFXFF_in_User_Setup !
#endif

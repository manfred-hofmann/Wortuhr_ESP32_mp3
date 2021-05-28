//******************************************************************************
// LedDriver_Sekunden.h
//******************************************************************************


#ifndef LEDDRIVER_SEK_H
#define LEDDRIVER_SEK_H
#include "Configuration.h"
#ifdef SEKUNDENLEDS
#include <Adafruit_NeoPixel.h>
#include "Colors.h"

class Sek_LedDriver
{
public:
    Sek_LedDriver();
    ~Sek_LedDriver();

    void clear();
    void show();
    uint32_t ColorHSV(uint16_t hue);
    void setPixel(uint8_t num, uint8_t color, uint8_t brightness);
    void setPixelRGB(uint8_t num, uint8_t red, uint8_t green, uint8_t blue );
private:
    Adafruit_NeoPixel *sek_strip;

};

#endif
#endif

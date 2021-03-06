//******************************************************************************
// LedDriver.h
//******************************************************************************


#ifndef LEDDRIVER_H
#define LEDDRIVER_H
#include "Configuration.h"
#include <Adafruit_NeoPixel.h>
#include "Colors.h"

class LedDriver
{
public:
    LedDriver();
    ~LedDriver();

    void clear();
    void show();
    void setPixel(uint8_t x, uint8_t y, uint8_t color, uint8_t brightness);
    void setPixel(uint8_t num, uint8_t color, uint8_t brightness);
    void setPixelRGB(uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue);
    void setPixelRGB(uint8_t num, uint8_t red, uint8_t green, uint8_t blue );
private:
    Adafruit_NeoPixel *strip;

};

#endif

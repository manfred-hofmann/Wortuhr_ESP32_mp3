//******************************************************************************
// LedDriver_Sekunden.cpp
//******************************************************************************

#include "LedDriver_Sekunden.h"
#ifdef SEKUNDENLEDS

Sek_LedDriver::Sek_LedDriver()
{
    sek_strip = new Adafruit_NeoPixel(NUMPIXELS_SEK, PIN_LEDS_DATA_SEK, NEOPIXEL_TYPE_SEK);
    sek_strip->begin();
}

Sek_LedDriver::~Sek_LedDriver()
{
}

void Sek_LedDriver::clear()
{
    sek_strip->clear();
}

void Sek_LedDriver::show()
{
    sek_strip->show();
}

uint32_t Sek_LedDriver::ColorHSV(uint16_t hue)
{
    return sek_strip->ColorHSV(hue);
}

void Sek_LedDriver::setPixel(uint8_t num, uint8_t color, uint8_t brightness)
{
    uint8_t red   = brightness * 0.0039 * defaultColors[color].red;
    uint8_t green = brightness * 0.0039 * defaultColors[color].green;
    uint8_t blue  = brightness * 0.0039 * defaultColors[color].blue;
    setPixelRGB(num, red, green, blue);
}


void Sek_LedDriver::setPixelRGB(uint8_t num, uint8_t red, uint8_t green, uint8_t blue )
{

  if ( NEOPIXEL_TYPE == NEO_WRGB + NEO_KHZ800 || NEOPIXEL_TYPE == NEO_GRBW + NEO_KHZ800 )
  {
    
    uint8_t white = 0xFF;
    if ( red < white ) white = red;
    if ( green < white ) white = green;
    if ( blue < white ) white = blue;
    sek_strip->setPixelColor(num, red-white, green-white, blue-white, white);

/* Mit Einstellen der Farbtemperatur:
  // Reference, currently set to 4500k white light:
  // https://andi-siess.de/rgb-to-color-temperature/
    const uint8_t kWhiteRedChannel = 255;
    const uint8_t kWhiteGreenChannel = 219;
    const uint8_t kWhiteBlueChannel = 186;
    static_assert(kWhiteRedChannel >= 255 || kWhiteGreenChannel >= 255 || kWhiteBlueChannel >= 255, "RGB Channel > 255 nicht erlaubt!");
    
    double whiteValueForRed = red * 255.0 / kWhiteRedChannel;
    double whiteValueForGreen = green * 255.0 / kWhiteGreenChannel;
    double whiteValueForBlue = blue * 255.0 / kWhiteBlueChannel;
  
    double minWhiteValue = min(whiteValueForRed, min(whiteValueForGreen, whiteValueForBlue));
    uint8_t white = (minWhiteValue <= 255 ? (uint8_t) minWhiteValue : 255);
  
    red   = (uint8_t)(red - minWhiteValue * kWhiteRedChannel / 255);
    green = (uint8_t)(green - minWhiteValue * kWhiteGreenChannel / 255);
    blue  = (uint8_t)(blue - minWhiteValue * kWhiteBlueChannel / 255);
    strip->setPixelColor(ledMap[num], red, green, blue, white);
    */
  }
  else
  {
    sek_strip->setPixelColor(num, red, green, blue);
  }
    
}
#endif

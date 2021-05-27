#ifndef YRNO_H
#define YRNO_H

#include <Arduino_JSON.h>
#include <WiFi.h>

#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include "Configuration.h"


//                                   engl.Original:deutsch  :Animation
static const char langmap_00[] PROGMEM = "clearsky:klarer Himmel:01";
static const char langmap_01[] PROGMEM = "cloudy:bewölkt:03";
static const char langmap_02[] PROGMEM = "fair:Schönwetter:02";
static const char langmap_03[] PROGMEM = "fog:Nebel:50";
static const char langmap_04[] PROGMEM = "heavyrain:heftiger Regen:09";
static const char langmap_05[] PROGMEM = "heavyrainandthunder:heftiger Regen mit Gewitter:12";
static const char langmap_06[] PROGMEM = "heavyrainshowers:starke Regenschauer:09";
static const char langmap_07[] PROGMEM = "heavysleet:heftiger Schneeregen:09";
static const char langmap_08[] PROGMEM = "heavysleetandthunder:heftiger Schneeregen mit Gewitter:12";
static const char langmap_09[] PROGMEM = "heavysleetshowers:heftiger Schneeschauer:13";

static const char langmap_10[] PROGMEM = "heavysleetshowersandthunder:heftiger Schneeschauer mit Gewitter:13";
static const char langmap_11[] PROGMEM = "heavysnow:starker Schneefall:13";
static const char langmap_12[] PROGMEM = "heavysnowandthunder:starker Schneefall und Gewitter:13";
static const char langmap_13[] PROGMEM = "heavysnowshowers:starker Schneefall:13";
static const char langmap_14[] PROGMEM = "heavysnowshowersandthunder:starker Schneefall mit Gewitter:13";
static const char langmap_15[] PROGMEM = "lightrain:leichter Regen:09";
static const char langmap_16[] PROGMEM = "lightrainandthunder:leichter Regen und Gewitter:12";
static const char langmap_17[] PROGMEM = "lightrainshowers:leichte Regenschauer:09";
static const char langmap_18[] PROGMEM = "lightrainshowersandthunder:leichte Regenschauer mit Gewitter:12";
static const char langmap_19[] PROGMEM = "lightsleet:leichter Schneeregen:09";

static const char langmap_20[] PROGMEM = "lightsleetandthunder:leichter Schneeregen mit Gewitter:09";
static const char langmap_21[] PROGMEM = "lightsleetshowers:leichter Graupelschauer:09";
static const char langmap_22[] PROGMEM = "lightsnow:leichter Schneefall:13";
static const char langmap_23[] PROGMEM = "lightsnowandthunder:leichter Schneefall mit Gewitter:13";
static const char langmap_24[] PROGMEM = "lightsnowshowers:leichte Schneeschauer:13";
static const char langmap_25[] PROGMEM = "lightssleetshowersandthunder:leichter Graupelschauer mit Gewitter:09";
static const char langmap_26[] PROGMEM = "lightssnowshowersandthunder:leichte Schneeschauer mit Gewitter:13";
static const char langmap_27[] PROGMEM = "partlycloudy:teils wolkig:02";
static const char langmap_28[] PROGMEM = "rain:Regen:09";
static const char langmap_29[] PROGMEM = "rainandthunder:Regen mit Gewitter:12";

static const char langmap_30[] PROGMEM = "rainshowers:Regenschauer:09";
static const char langmap_31[] PROGMEM = "rainshowersandthunder:Regenschauer mit Gewitter:12";
static const char langmap_32[] PROGMEM = "sleet:Schneeregen:09";
static const char langmap_33[] PROGMEM = "sleetandthunder:Schneeregen mit Gewitter:12";
static const char langmap_34[] PROGMEM = "sleetshowers:Graupelschauer:09";
static const char langmap_35[] PROGMEM = "snow:Schnee:13";
static const char langmap_36[] PROGMEM = "snowandthunder:Schnee mit Gewitter:13";
static const char langmap_37[] PROGMEM = "snowshowers:Schneeschauer:13";
static const char langmap_38[] PROGMEM = "snowshowersandthunder:Schneeschauer mit Gewitter:13";


static const char* const langmap_table[] PROGMEM = 
{
  langmap_00,langmap_01,langmap_02,langmap_03,langmap_04,langmap_05,langmap_06,langmap_07,langmap_08,langmap_09,
  langmap_10,langmap_11,langmap_12,langmap_13,langmap_14,langmap_15,langmap_16,langmap_17,langmap_18,langmap_19,
  langmap_20,langmap_21,langmap_22,langmap_23,langmap_24,langmap_25,langmap_26,langmap_27,langmap_28,langmap_29,
  langmap_30,langmap_31,langmap_32,langmap_33,langmap_34,langmap_35,langmap_36,langmap_37,langmap_38
};


class yrno
{
  public:
  yrno();
  ~yrno();
    uint16_t symbol_id;
    String symbol_text;
    String day_night;
    String symbol_code;
    String animation_code;
    double regenmenge;
    double temperature;
    double windspeed;
    uint8_t humidity;
    uint8_t clouds;
    uint16_t pressure;
    
    String regenmenge_units;
    String temperature_units;
    String windspeed_units;
    String humidity_units;
    String clouds_units;
    String pressure_units;
    
  uint16_t getOutdoorConditions(double latitude, double longitude );

  private:
   
};

#endif

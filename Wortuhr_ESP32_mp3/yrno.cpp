//******************************************************************************
// yrno.cpp - Get weather data from https://api.met.no/ (yr.no)
//******************************************************************************

#include "yrno.h"

yrno::yrno()
{
}

yrno::~yrno()
{
}

uint16_t yrno::getOutdoorConditions(double latitude, double longitude )
{
  uint8_t retcode=0;
  String response;
  String units;
  String werte;
  String symbol_en;
  String symbolcomp_en;
  String symbol_de;
  String animation;
  uint8_t wertschrittwerk = 0;

#ifdef DEBUG_YRNO
  Serial.println("\nStarting connection to server https://api.met.no");
#endif

WiFiClientSecure *yrnoclient = new WiFiClientSecure;

yrnoclient -> setInsecure();                  //ohne Certificate Check

  {
     HTTPClient https;
  
#ifdef DEBUG_YRNO
    Serial.println("connected to server");
#endif
    String url = "https://api.met.no/weatherapi/locationforecast/2.0/compact?lat=" + String(latitude) + "&lon=" + String(longitude);
    if (https.begin(*yrnoclient, url))   // HTTPS
    {
      int httpCode = https.GET();
      if (httpCode == HTTP_CODE_OK )
      {
        String payload = https.getString();
        int unitsstart = payload.indexOf("\"units\":");
        if (  unitsstart > 0 ) 
        {
          int unitsende = payload.indexOf("}",unitsstart);
          units = "{\n" + payload.substring(unitsstart,unitsende) + "}\n}";
#ifdef DEBUG_YRNO
          Serial.printf("Units:%i - %i\n %s\n",unitsstart,unitsende,units.c_str() );
#endif
        }
        int wertestart = payload.indexOf("\"time\":");          //suche nach "time":
        if (wertestart > 0 && wertschrittwerk == 0 )            // wenn es das 2. Mal gefunden wurde brechen wir ab.
        {
          wertschrittwerk = 1;
          int werteende = payload.indexOf("\"time\":",wertestart+10);
          werte = "{" + payload.substring(wertestart,werteende-2);
#ifdef DEBUG_YRNO
          Serial.printf("Werte:%i - %i\n %s\n",wertestart,werteende,werte.c_str() );
#endif
        }
      }
      else 
      {
#ifdef DEBUG_YRNO
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
#endif
        retcode = retcode + 64;
      }
      https.end();
    }
    else 
    {
      Serial.printf("[HTTPS] Unable to connect\n");
      retcode = retcode + 64;
    }
    delete yrnoclient;
  }
  
  if (retcode == 0 && wertschrittwerk == 1)
  {
    JSONVar weatherArray = JSON.parse(werte);
    if(! isnan((double)weatherArray["data"]["instant"]["details"]["air_temperature"]) )
    {
      temperature = (double)weatherArray["data"]["instant"]["details"]["air_temperature"];
    }
    else
    {
      retcode = retcode + 1;
    }
    if(! isnan((int)weatherArray["data"]["instant"]["details"]["relative_humidity"]))
    {
      humidity = (int)weatherArray["data"]["instant"]["details"]["relative_humidity"];
    }
    else
    {
      retcode = retcode + 2;
    }
    if(! isnan((int)weatherArray["data"]["instant"]["details"]["air_pressure_at_sea_level"]))
    {
      pressure = (int)weatherArray["data"]["instant"]["details"]["air_pressure_at_sea_level"];
    }
    else
    {
      retcode = retcode + 4;
    }  
    if(! isnan((int)weatherArray["data"]["instant"]["details"]["cloud_area_fraction"]))
    {
      clouds = (int)weatherArray["data"]["instant"]["details"]["cloud_area_fraction"];
    }
    else
    {
      retcode = retcode + 8;
    }
    if(! isnan((int)weatherArray["data"]["instant"]["details"]["wind_speed"]))
    {
      windspeed = (int)weatherArray["data"]["instant"]["details"]["wind_speed"];  
    }
    else
    {
      retcode = retcode + 16;
    }
    
    symbol_code = weatherArray["data"]["next_1_hours"]["summary"]["symbol_code"];
    regenmenge = (double)weatherArray["data"]["next_1_hours"]["details"]["precipitation_amount"];


    JSONVar unitsArray = JSON.parse(units);
    regenmenge_units = unitsArray["units"]["precipitation_amount"];
    temperature_units = unitsArray["units"]["air_temperature"];
    windspeed_units = unitsArray["units"]["wind_speed"];
    humidity_units = unitsArray["units"]["relative_humidity"];
    clouds_units = unitsArray["units"]["cloud_area_fraction"];
    pressure_units = unitsArray["units"]["air_pressure_at_sea_level"];

    for ( uint16_t i = 0; i < sizeof(langmap_table)/4; i++)
    {
      response = String(langmap_table[i]); 
      symbol_en = response.substring(0,response.indexOf(":"));
      symbol_de = response.substring(response.indexOf(":")+1, response.lastIndexOf(":"));
      animation = response.substring(response.lastIndexOf(":")+1);
      if ( symbol_code.lastIndexOf("_") > 0 )
      {
        symbolcomp_en = symbol_code.substring(0,symbol_code.lastIndexOf("_"));
        day_night = symbol_code.substring(symbol_code.lastIndexOf("_"));
      }
      else
      {
        symbolcomp_en = symbol_code;
        day_night = "";
      }
      if ( symbol_en == symbolcomp_en ) {
        symbol_text = symbol_de;
        symbol_id = i;
        animation_code = animation;
        break;
      }
    }

#ifdef DEBUG_YRNO
    Serial.printf("Symbol-ID: %i\n",symbol_id);
    Serial.printf("Symbol-Text: %s\n",symbol_text.c_str());
    Serial.printf("Symbol-DayNight: %s\n",day_night.c_str());
    Serial.printf("Symbol: %s\n",symbol_code.c_str());
    Serial.printf("Animation: %s\n",animation_code.c_str());
    Serial.printf("Temperatur: %.1f %s\n",temperature, temperature_units.c_str());
    Serial.printf("Luftfeuchte: %i %s\n",humidity, humidity_units.c_str());
    Serial.printf("Luftdruck: %i %s\n",pressure, pressure_units.c_str());
    Serial.printf("Wolken: %i %s\n",clouds, clouds_units.c_str());
    Serial.printf("Windgeschwindigkeit: %.1f %s\n",windspeed, windspeed_units.c_str());
    Serial.printf("Regenmenge: %.1f %s\n",regenmenge, regenmenge_units.c_str());
#endif
    
  }
  else
  {
    retcode = 32;
  }

  return retcode;
}

//******************************************************************************
// Settings.cpp
//******************************************************************************

#include "Settings.h"

Settings::Settings()
{
    loadFromNVS();
}

Settings::~Settings()
{
}

// Load settings from NVS
void Settings::loadFromNVS()
{
    Serial.println("Settings load from NVS.");
    Preferences preferences;
    preferences.begin("Settings", false);
    mySettings.version =              preferences.getUInt  ("version",0);
    Serial.printf ("NVS-Version: %i\n",mySettings.version); 
    if ( mySettings.version != SETTINGS_VERSION ) 
    {
      Serial.println("Init Settings!");
      preferences.clear();
    }

    mySettings.systemname =           preferences.getString("systemname",WIFIHOSTNAME);
    mySettings.wlanssid =             preferences.getString("wlanssid",WIFI_SID);
    mySettings.wlanpw =               preferences.getString("wlanpw",WIFI_PW);
    mySettings.useAbc =               preferences.getBool  ("useAbc", true);
    mySettings.brightness =           preferences.getUShort("brightness", 90);
    mySettings.color =                preferences.getUChar ("color", WHITE);
    mySettings.colorChange =          preferences.getUChar ("colorChange", COLORCHANGE_FIVE);
    mySettings.transition =           preferences.getUChar ("transition",TRANSITION_ALLE_NACHEINANDER);
    mySettings.modeChange =           preferences.getBool  ("modeChange",false);
    mySettings.itIs =                 preferences.getBool  ("itIs",true);
    mySettings.alarm1 =               preferences.getBool  ("alarm1",false);
    mySettings.alarm1Time =           preferences.getULong ("alarm1Time",0);
    mySettings.alarm1Weekdays =       preferences.getUChar ("alarm1Weekdays",0b11111110);
    mySettings.alarm2 =               preferences.getBool  ("alarm2",false);
    mySettings.alarm2Time =           preferences.getULong ("alarm2Time",0);
    mySettings.alarm2Weekdays =       preferences.getUChar ("alarm2Weekdays",0b11111110);
    mySettings.nightOffTime =         preferences.getULong ("nightOffTime",10800);
    mySettings.dayOnTime =            preferences.getULong ("dayOnTime",10860);
    mySettings.hourBeep =             preferences.getBool  ("hourBeep",true);
    mySettings.volume =               preferences.getShort ("volume",90);
    mySettings.sprecher =             preferences.getBool  ("sprecher",true);  //vicki
    mySettings.randomsound =          preferences.getBool  ("randomsound",false);
    mySettings.weekdaysoundfile[0] =  preferences.getUChar ("wdsoundfile0",8);  //Sonntag
    mySettings.weekdaysoundfile[1] =  preferences.getUChar ("wdsoundfile1",0);  //Montag
    mySettings.weekdaysoundfile[2] =  preferences.getUChar ("wdsoundfile2",1);  //Dienstag
    mySettings.weekdaysoundfile[3] =  preferences.getUChar ("wdsoundfile3",2);  //Mittwoch
    mySettings.weekdaysoundfile[4] =  preferences.getUChar ("wdsoundfile4",3);  //Donnerstag
    mySettings.weekdaysoundfile[5] =  preferences.getUChar ("wdsoundfile5",4);  //Freitag
    mySettings.weekdaysoundfile[6] =  preferences.getUChar ("wdsoundfile6",5);  //Samstag
   
    mySettings.weekendlater =         preferences.getBool  ("weekendlater",true);
    mySettings.vickihans24h =         preferences.getBool  ("vickihans24h",false);
    mySettings.ntphost =              preferences.getString("ntphost",NTP_SERVER);
    mySettings.corner_color =         preferences.getUChar ("co_color", ORANGE);
    mySettings.corner_colorChange =   preferences.getUChar ("co_colorChange", COLORCHANGE_MAIN);
    mySettings.highscore[0] =         preferences.getUShort("highscore0", 0);
    mySettings.highscore[1] =         preferences.getUShort("highscore1", 0);
    mySettings.highscore[2] =         preferences.getUShort("highscore2", 0);
    mySettings.highscore[3] =         preferences.getUShort("highscore3", 0);
    mySettings.highscore[4] =         preferences.getUShort("highscore4", 0);
    mySettings.standort_hoehe =       preferences.getUShort("standort_hoehe", HOEHE_UEBER_0);
    mySettings.auto_mode_change =     preferences.getUChar ("amc", AUTO_MODECHANGE_TIME / 60);
    mySettings.latitude =             preferences.getDouble("latitude", LATITUDE);
    mySettings.longitude =            preferences.getDouble("longitude", LONGITUDE);

    mySettings.sekmode =              preferences.getUChar ("sekmode",1); // 0 : aus 1: 1h/Farbverlauf 2: wie Hauptfarbe 3: festeFarbe
    mySettings.sekcolor =             preferences.getUInt  ("sekcolor",0xFFFFFF);
    
    preferences.end();
    if ( mySettings.version != SETTINGS_VERSION ) saveToNVS();

}

// Write settings to NVS
void Settings::saveToNVS()
{
    Serial.println("Settings saved to NVS.");
    Preferences preferences;
    preferences.begin("Settings", false);  
    preferences.putUInt("version",SETTINGS_VERSION);
    preferences.putString("systemname",mySettings.systemname);
    preferences.putString("wlanssid",mySettings.wlanssid);
    preferences.putString("wlanpw",mySettings.wlanpw);
    preferences.putBool  ("useAbc", mySettings.useAbc);
    preferences.putUShort("brightness", mySettings.brightness);
    preferences.putUChar ("color", mySettings.color);
    preferences.putUChar ("colorChange", mySettings.colorChange);
    preferences.putUChar ("transition", mySettings.transition);
    preferences.putBool  ("modeChange",mySettings.modeChange);
    preferences.putBool  ("itIs",mySettings.itIs);
    preferences.putBool  ("alarm1",mySettings.alarm1);
    preferences.putULong ("alarm1Time",mySettings.alarm1Time);
    preferences.putUChar ("alarm1Weekdays",mySettings.alarm1Weekdays);
    preferences.putBool  ("alarm2",mySettings.alarm2);
    preferences.putULong ("alarm2Time",mySettings.alarm2Time);
    preferences.putUChar ("alarm2Weekdays",mySettings.alarm2Weekdays);
    preferences.putULong ("nightOffTime",mySettings.nightOffTime);
    preferences.putULong ("dayOnTime",mySettings.dayOnTime);
    preferences.putBool  ("hourBeep",mySettings.hourBeep);
    preferences.putShort ("volume",mySettings.volume);
    preferences.putBool  ("sprecher",mySettings.sprecher);
    preferences.putBool  ("randomsound",mySettings.randomsound);
    preferences.putUChar ("wdsoundfile0",mySettings.weekdaysoundfile[0]);
    preferences.putUChar ("wdsoundfile1",mySettings.weekdaysoundfile[1]);
    preferences.putUChar ("wdsoundfile2",mySettings.weekdaysoundfile[2]);
    preferences.putUChar ("wdsoundfile3",mySettings.weekdaysoundfile[3]);
    preferences.putUChar ("wdsoundfile4",mySettings.weekdaysoundfile[4]);
    preferences.putUChar ("wdsoundfile5",mySettings.weekdaysoundfile[5]);
    preferences.putUChar ("wdsoundfile6",mySettings.weekdaysoundfile[6]);
    preferences.putBool  ("weekendlater",mySettings.weekendlater);
    preferences.putBool  ("vickihans24h",mySettings.vickihans24h);
    preferences.putString("ntphost",mySettings.ntphost);
    preferences.putUChar ("co_color", mySettings.corner_color);
    preferences.putUChar ("co_colorChange", mySettings.corner_colorChange);
    preferences.putUShort("highscore0", mySettings.highscore[0]);
    preferences.putUShort("highscore1", mySettings.highscore[1]);
    preferences.putUShort("highscore2", mySettings.highscore[2]);
    preferences.putUShort("highscore3", mySettings.highscore[3]);
    preferences.putUShort("highscore4", mySettings.highscore[4]);
    preferences.putUShort("standort_hoehe", mySettings.standort_hoehe);
    preferences.putUChar ("amc", mySettings.auto_mode_change);
    preferences.putDouble ("latitude", mySettings.latitude);
    preferences.putDouble ("longitude", mySettings.longitude);
    preferences.putUChar ("sekmode", mySettings.sekmode);
    preferences.putUInt  ("sekcolor", mySettings.sekcolor);
    
    preferences.end();
}

//******************************************************************************
// Configuration.h
//******************************************************************************

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

//******************************************************************************
// Software settings
//******************************************************************************

#define WIFIHOSTNAME "WU_ESP32"                // Das ist der default Hostname/Systemname. Der eigentliche Systemname wird in Settings eingestellt.
#define WIFI_SETUP_TIMEOUT 30                  // So lange wird versucht eine Verbindung zum WLAN aufzubauen. Ab dann wird ein AP (AccessPoint) zum eingeben der WiFi Parameter gestartet
#define WIFI_SID "Wlan-SID"                    // Die default WIFI-SID. Die eigentliche WIFI-SID wird in Settings eingestellt.
#define WIFI_PW "Wlan-Passwort"                // Das default WIFI Passwort. Die eigentliche WIFI Passwort wird in Settings eingestellt.
#define OTA_PASS "1234"                        // Passwort für den OTA (Over the Air) Update
#define NTP_SERVER "fritz.box"                 // Das ist der default Name des Zeitservers. Der eigentliche Zeitserver wird in Settings eingestellt.
#define SHOW_IP                                // Zeigt die IP-Adresse beim Start
#define WIFI_BEEPS                             // ob die WLAN Verbunden Meldung kommt

//#define NONE_TECHNICAL_ZERO                  // ob die Null bei Feed mit oder ohne Schrägstrich angezeigt wird.
#define AUTO_MODECHANGE_TIME 180               // Default AutoMode Change Periode. Die eigentliche Periode wird in Settings eingestellt.
#define SHOW_MODE_TIMEOUT 3500                 // Timer bis es im Mode Modus zum nächsten Mode geht
#define FEED_SPEED 120                         // wie schnell die Buchstaben über die Uhr huschen
#define TRANSITION_SPEED 90                    // wie schnell die Transitions laufen

#define MAXEVENTS 25                           // wie viele Events maximal angelegt werden können                           
#define EVENT_TIME 1800                        // Das ist die default Event Intervall. Der eigentliche Intervall wird am Event definiert

#define ALARM_LED_COLOR RED                    // Farbe der Alarm LED
#define ABUSE_CORNER_LED_FOR_ALARM             // Rechte obere Minuten LED wird zur Alarm LED

//#define POWERON_SELFTEST                     // LEDs werden beim anschalten mit versch. Farben getestet. Der Test kann auch im Mode Modus bei nochmalige betätigen des ModeButtons während der Sekunden Ausgabe gestartet werden. 
// welche Modes gibt es:
#define SHOW_MODE_ANSAGE                       
#define SHOW_MODE_SECONDS
#define SHOW_MODE_WEEKDAY
#define SHOW_MODE_DATE
#define SHOW_MODE_MOONPHASE
#define SHOW_MODE_WETTER
#define SHOW_MODE_TEST


//#define FRONTCOVER_EN
#define FRONTCOVER_DE_DE
//#define FRONTCOVER_DE_SW
//#define FRONTCOVER_DE_BA
//#define FRONTCOVER_DE_SA
//#define FRONTCOVER_DE_MKF_DE
//#define FRONTCOVER_DE_MKF_SW
//#define FRONTCOVER_DE_MKF_BA
//#define FRONTCOVER_DE_MKF_SA
//#define FRONTCOVER_D3
//#define FRONTCOVER_CH
//#define FRONTCOVER_CH_GS
//#define FRONTCOVER_ES
//#define FRONTCOVER_FR
//#define FRONTCOVER_IT
//#define FRONTCOVER_NL
//#define FRONTCOVER_BINARY

//******************************************************************************
// Timezone
//******************************************************************************

//#define TIMEZONE_IDLW  // IDLW  International Date Line West UTC-12
//#define TIMEZONE_SST   // SST   Samoa Standard Time UTC-11
//#define TIMEZONE_HST   // HST   Hawaiian Standard Time UTC-10
//#define TIMEZONE_AKST  // AKST  Alaska Standard Time UTC-9
//#define TIMEZONE_USPST // USPST Pacific Standard Time (USA) UTC-8
//#define TIMEZONE_USMST // USMST Mountain Standard Time (USA) UTC-7
//#define TIMEZONE_USAZ  // USAZ  Mountain Standard Time (USA) UTC-7 (no DST)
//#define TIMEZONE_USCST // USCST Central Standard Time (USA) UTC-6
//#define TIMEZONE_USEST // USEST Eastern Standard Time (USA) UTC-5
//#define TIMEZONE_AST   // AST   Atlantic Standard Time UTC-4
//#define TIMEZONE_BST   // BST   Eastern Brazil Standard Time UTC-3
//#define TIMEZONE_VTZ   // VTZ   Greenland Eastern Standard Time UTC-2
//#define TIMEZONE_AZOT  // AZOT  Azores Time UTC-1
//#define TIMEZONE_GMT   // GMT   Greenwich Mean Time UTC
#define TIMEZONE_CET     // CET   Central Europe Time UTC+1
//#define TIMEZONE_EST   // EST   Eastern Europe Time UTC+2
//#define TIMEZONE_MSK   // MSK   Moscow Time UTC+3 (no DST)
//#define TIMEZONE_GST   // GST   Gulf Standard Time UTC+4
//#define TIMEZONE_PKT   // PKT   Pakistan Time UTC+5
//#define TIMEZONE_BDT   // BDT   Bangladesh Time UTC+6
//#define TIMEZONE_JT    // JT    Java Time UTC+7
//#define TIMEZONE_CNST  // CNST  China Standard Time UTC+8
//#define TIMEZONE_HKT   // HKT   Hong Kong Time UTC+8
//#define TIMEZONE_PYT   // PYT   Pyongyang Time (North Korea) UTC+8.5
//#define TIMEZONE_CWT   // CWT   Central West Time (Australia) UTC+8.75
//#define TIMEZONE_JST   // JST   Japan Standard Time UTC+9
//#define TIMEZONE_ACST  // ACST  Australian Central Standard Time UTC+9.5
//#define TIMEZONE_AEST  // AEST  Australian Eastern Standard Time UTC+10
//#define TIMEZONE_LHST  // LHST  Lord Howe Standard Time UTC+10.5
//#define TIMEZONE_SBT   // SBT   Solomon Islands Time UTC+11
//#define TIMEZONE_NZST  // NZST  New Zealand Standard Time UTC+12



#define SERIAL_SPEED 115200

#define NUMPIXELS 115
#define ESP_LED

// Gibt es eine LED Kette für die Sekunden (nicht vergessen den Anschluß dafür zu definieren siehe weiter unten bei ESP32 Anschlüsse)
//#define SEKUNDENLEDS           
//#define NUMPIXELS_SEK 60                        // Anzahl der Sekunden LEDS
//#define SEK0POSLED 15                           // Position der Sekunde 0 LED


// Einstellen der min/max Helligkeiten
#define MIN_BRIGHTNESS 5
#define MAX_BRIGHTNESS 255
#define TEST_BRIGHTNESS 80


// Touch Empfindlichkeit
#define MODE_TOUCH_SENS 3                        // Empfindlichkeit der Mode Touch Sensoren 1-20 (je kleiner desto empfindlicher)
#define ONOFF_TOUCH_SENS 3                       // Empfindlichkeit der OnOff Touch Sensoren 1-20 (je kleiner desto empfindlicher)

// Ist ein BME280 an Board
#define SENSOR_BME280
#define SEALEVELPRESSURE_HPA (1013.25)
#define BME_TEMPERATURE_OFFSET -1.2              // Temperaturkorrektur
#define BME_HUMIDITY_OFFSET +0.1                 // Luftfeuchtekorrektur

#define SunRiseLib                               // Sonnenaufgang/Sonnenuntergang wird über die Lib SunRise.h berechnet.
                                                 // Die RunRise Lib ist in der Bibliotheksverwaltung zu finden.
#define YRNO   
#define LONGITUDE 9.83                           // Default LONGITUDE/LATITUDE. Der Standortwerte werden in Settings eingestellt.
#define LATITUDE 50.66                           // Dafür wird der Standort benötigt. Kann z.B. über google maps erfolgen.
#define HOEHE_UEBER_0 130                        // Hier die default Höhe über NN des Wohnortes eintragen.Der eigentliche Wert wird in Settings eingestellt.

#define YRNO_PERIODE 1800                        // wie oft in Sekunden yrno aufgerufen wird
#define YRNO_MAX_ERROR 20                        // bei Fehler: wie oft es pro Tag versucht wird bis es aufgegeben wird.


#define LUFTDRUCKMIN 975                         // Hier den zu erwartenden minimalen Luftdruck eintragen (Baseline im Diagramm)
// Parameter für die Berechnung des Luftdrucks auf Meeresniveau:
#define FALLBESCHLEUNIGUNG 9.80665
#define GASKONSTANTE 287.05
#define KELVIN_0 273.15
#define TEMPERATURGRADIENT 0.00325
#define EULERSCHE_ZAHL 2.7183

// Schwellen für steigend/fallender Luftdruck:
#define LUFTDRUCK_DIFF_STEIGEND 30
#define LUFTDRUCK_DIFF_LEICHTSTEIGEND 15
#define LUFTDRUCK_DIFF_LEICHTFALLEND -15
#define LUFTDRUCK_DIFF_FALLEND -30

// Lichtabhängiger Widerstand an Board?
#define LDR
//#define LDR_IS_INVERSE

//#define BUZZER
//#define BUZZTIME_ALARM_1 10
//#define BUZZTIME_ALARM_2 10
//#define BUZZTIME_TIMER 10

// MP3 Spieler vorhanden:
#define AUDIO_SOUND

#ifdef AUDIO_SOUND
#define BUZZTIME_ALARM_1 10           // wie lange der Alarm1 an ist
#define BUZZTIME_ALARM_2 10           // wie lange der Alarm2 an ist
#define BUZZTIME_TIMER 5              // wie lange der Timeralarm an ist

// Basiswerte der Soundfiles
#define AUDIO_BASENR0 0     // 0 s1
#define AUDIO_BASENR1 20    // 1 s2
#define AUDIO_BASENR2 40    // 2 s3
#define AUDIO_BASENR3 60    // 3 s4
#define AUDIO_BASENR4 80    // 4 kuckuck
#define AUDIO_BASENR5 120   // 5 bing
#define AUDIO_BASENR6 140   // 6 kirche
#define AUDIO_BASENR7 100   // 7 westminster 1
#define AUDIO_BASENR8 160   // 8 westminster 2
#define AUDIO_BASENR9 180   // 9 alte Uhr
#define AUDIO_BASENR10 200  // 10 ding
#define AUDIO_BASENR11 220  // 11 Hund und Katz
#define AUDIO_BASENR12 240  // 12 Tod

#define AUDIO_BASENR_VICKI 1000      // 13 vicki
#define AUDIO_BASENR_HANS  2000      // 14 hans
#define AUDIO_BASENR_RANDOM   0      // 15 Random


// Sound Web-Anzeigenamen in Settings:
#define AUDIO_WEBNAME0  "Sound 1"               // 0 s1
#define AUDIO_WEBNAME1  "Sound 2"               // 1 s2
#define AUDIO_WEBNAME2  "Sound 3"               // 2 s3
#define AUDIO_WEBNAME3  "Sound 4"               // 3 s4
#define AUDIO_WEBNAME4  "Kuckuck"               // 4 kuckuck
#define AUDIO_WEBNAME5  "Bing"                  // 5 bing
#define AUDIO_WEBNAME6  "Kirche"                // 6 kirche
#define AUDIO_WEBNAME7  "Westminster 1"         // 7 westminster 1
#define AUDIO_WEBNAME8  "Westminster 2"         // 8 westminster 2
#define AUDIO_WEBNAME9  "alte Uhr"              // 9 alte Uhr
#define AUDIO_WEBNAME10 "Ding"                  // 10 Ding
#define AUDIO_WEBNAME11 "Hund und Katz"         // 11 Hund und Katz
#define AUDIO_WEBNAME12 "Tod"                   // 12 Tod

// Lautstärke Level pro Stunde in Prozent:
#define AUDIO_H00 30
#define AUDIO_H01 20
#define AUDIO_H02 10
#define AUDIO_H03 10
#define AUDIO_H04 10
#define AUDIO_H05 20
#define AUDIO_H06 30
#define AUDIO_H07 50
#define AUDIO_H08 80
#define AUDIO_H09 90
#define AUDIO_H10 100
#define AUDIO_H11 100
#define AUDIO_H12 100
#define AUDIO_H13 100
#define AUDIO_H14 100
#define AUDIO_H15 100
#define AUDIO_H16 100
#define AUDIO_H17 100
#define AUDIO_H18 100
#define AUDIO_H19 100
#define AUDIO_H20 100
#define AUDIO_H21 90
#define AUDIO_H22 80
#define AUDIO_H23 60
#define AUDIO_H24 30

#endif //Ende AUDIO_SOUND

// Das LED Layout (Siehe in LedDriver.cpp):
#define LED_LAYOUT_HORIZONTAL_2
//#define LED_LAYOUT_VERTICAL_1
//#define LED_LAYOUT_VERTICAL_2
//#define LED_LAYOUT_VERTICAL_3

//******************************************************************************
// Einstellungen LED Type
//******************************************************************************

#define NEOPIXEL_TYPE NEO_GRB + NEO_KHZ800     // see Adafruit_NeoPixel.h for help

#define NEOPIXEL_TYPE_SEK NEO_GRB + NEO_KHZ800
//#define NEOPIXEL_TYPE_SEK NEO_GRBW + NEO_KHZ800

////#define NEOPIXEL_TYPE NEO_WRGB + NEO_KHZ800

//******************************************************************************
// Misc
//******************************************************************************

// Debug Schalter:

//#define DEBUG 1
//#define DEBUG_EVENTS
//#define DEBUG_ANIMATION
//#define DEBUG_GAME
//#define DEBUG_WEB
//#define DEBUG_IR
//#define DEBUG_MATRIX
//#define DEBUG_FPS
//#define DEBUG_YRNO
//#define DEBUG_TOUCH


//******************************************************************************
// ESP32 Anschlüsse:
//******************************************************************************

#define PIN_WIRE_SCL    SCL  // GPIO22   SCL 
#define PIN_WIRE_SDA    SDA  // GPIO21   SDA
//#define PIN_MODE_BUTTON  23  // GPIO23  
#define PIN_LED           2  // GPIO2   LED_BUILTIN  ESP32_LED
#define PIN_AUDIO_RX     16  // GPIO16  
#define PIN_AUDIO_TX     17  // GPIO17  
#define PIN_AUDIO_BUSY   26  // GPIO26  
//#define PIN_BUZZER       18   // GPIO18
#define PIN_LEDS_DATA    5   // GPIO5   Wortuhr LEDs
#define PIN_LDR          36  // GPIO36  Analog-in
#define PIN_MODE_BUTTON_TOUCH T3   //GPIO15 
#define PIN_ONOFF_BUTTON_TOUCH T4  //GPIO13

//#define PIN_LEDS_DATA_SEK 19       // Sekunden LEDs

#endif

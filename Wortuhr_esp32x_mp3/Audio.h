//******************************************************************************
// Audio.h
//******************************************************************************

#ifndef AUDIO_H
#define AUDIO_H

#include <Arduino.h>
#include <TimeLib.h>
#include "Configuration.h"
#include "Settings.h"
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

extern Settings settings;
extern DFRobotDFPlayerMini Mp3Player;
extern bool MODE_BUTTON_BOOL;
extern uint8_t VOLUME_ALT;

void Temperaturansage(int ANSAGEBASE, bool in_out, float fTemperature, uint8_t setvolume);
void Humidityansage(int ANSAGEBASE, bool in_out, float fHumidity, uint8_t setvolume);
void Zeitansage(int ANSAGEBASE, uint8_t setvolume);
void Wochentagansage(int ANSAGEBASE, uint8_t setvolume);
void Datumsansage(int ANSAGEBASE, uint8_t setvolume);
void Play_MP3(int filenr, bool warte_bis_fertig, uint16_t setvolume);


#endif

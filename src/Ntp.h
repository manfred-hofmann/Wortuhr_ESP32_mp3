//******************************************************************************
// Ntp.h - Get UTC time from NTP
//******************************************************************************

#ifndef NTP_H
#define NTP_H

#include <WiFi.h>
#include <TimeLib.h>
#include <WiFiUDP.h>

class Ntp
{
public:
    Ntp();
    ~Ntp();

    time_t getTime(String server);

private:

};

#endif

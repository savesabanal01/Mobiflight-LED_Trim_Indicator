#pragma once

#include "Arduino.h"

class Trim_Indicator
{
public:
    Trim_Indicator(uint8_t Pin1, uint8_t Pin2);
    void begin();
    void attach(uint16_t Pin3, char *init);
    void detach();
    void set(int16_t messageID, char *setPoint);
    void update();

private:
    bool    _initialised;
    uint8_t _pin1, _pin2, _pin3;

    uint16_t LEDPosition = 11;
    uint16_t prevLEDPosition = 11;
    uint16_t LEDDirection = 0;
    uint16_t LEDBrightness = 20;


    // Function declaration
    double scaleValue(float x, float in_min, float in_max, float out_min, float out_max);
    void setLEDPosition(double value);
    void setLEDDirection(uint16_t value);
    void setLEDBrightness(uint16_t value);
    
};
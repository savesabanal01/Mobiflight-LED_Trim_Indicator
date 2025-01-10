#include "Trim_Indicator.h"
#include "allocateMem.h"
#include "commandmessenger.h"
#include <FastLED.h>

#define LED_PIN 2
#define NUM_LEDS 22 // 150 LEDs in the full strip

CRGB leds[NUM_LEDS];


/* **********************************************************************************
    This is just the basic code to set up your custom device.
    Change/add your code as needed.
********************************************************************************** */

Trim_Indicator::Trim_Indicator(uint8_t Pin1, uint8_t Pin2)
{
    _pin1 = Pin1;
    _pin2 = Pin2;
}

void Trim_Indicator::begin()
{
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(20);
  leds[LEDPosition] = CRGB::Blue;
  FastLED.show();

}

void Trim_Indicator::attach(uint16_t Pin3, char *init)
{
    _pin3 = Pin3;
}

void Trim_Indicator::detach()
{
    if (!_initialised)
        return;
    _initialised = false;
}

void Trim_Indicator::set(int16_t messageID, char *setPoint)
{
    /* **********************************************************************************
        Each messageID has it's own value
        check for the messageID and define what to do.
        Important Remark!
        MessageID == -2 will be send from the board when PowerSavingMode is set
            Message will be "0" for leaving and "1" for entering PowerSavingMode
        MessageID == -1 will be send from the connector when Connector stops running
        Put in your code to enter this mode (e.g. clear a display)

    ********************************************************************************** */
    // int32_t  data = atoi(setPoint);
    // uint16_t output;

    // do something according your messageID
    switch (messageID) {
    case -1:
        // tbd., get's called when Mobiflight shuts down
    case -2:
        // tbd., get's called when PowerSavingMode is entered
    case 0:
        // output = (uint16_t)data;
        // data   = output;
        setLEDPosition(atof(setPoint));
        break;
    case 1:
        /* code */
        setLEDDirection(atoi(setPoint));
        break;
    case 2:
        setLEDBrightness(atoi(setPoint));
        /* code */
        break;
    default:
        break;
    }

    if(prevLEDPosition != LEDPosition)
    {
        FastLED.setBrightness(LEDBrightness);
        FastLED.clear();
        FastLED.show();
        leds[LEDPosition] = CRGB::Blue;
        FastLED.show();
    }
    
}

void Trim_Indicator::update()
{
    // Do something which is required regulary
}

void Trim_Indicator::setLEDDirection(uint16_t value)
{
    LEDDirection = value;
}

void Trim_Indicator::setLEDPosition(double value)
{

    if (LEDDirection == 0)
        LEDPosition = (uint16_t)(scaleValue(value, 1.0, -1.0, 1, 21));
    else if (LEDDirection == 1)
        LEDPosition = (uint16_t)(scaleValue(value, -1.0, 1.0, 1, 21));
}

void Trim_Indicator::setLEDBrightness(uint16_t value)
{
    if (LEDBrightness >= 0 && LEDBrightness <=100)
    {
        LEDBrightness = value;
    }
}

double Trim_Indicator::scaleValue(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
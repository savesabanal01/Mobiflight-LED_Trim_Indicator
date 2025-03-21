> [!NOTE]  
> This is a custom Mobilfight Firmware to use the WS2812B programmble LED strip with an Arduino Nano. It has been developed using the Mobiflight Custom Device (Community Device) (https://github.com/MobiFlight/MobiFlight-Connector/wiki/Using-a-pre-build-custom-device)

## Prerequisites
* Arduino Nano
* WS2812B Programmable LED strip

## Instructions
1. You need 22 LEDs from the LED strip. Please cut the LED strip so that you have 22 LEDs.
2. Connect the following pins of the WS2812B to the pins of the Arduino Nano:
   a. GND pin to GND of the Nano
   b. +5V pin to the +5V pin of the Nano
   c. Din pin to GPIO 2 (pin 2) of the Nano
4. Flash the Mobiflightr custom firmware in Mobiflight. The firmware is Trim Indicator_2.5.1.zip that can be found under the "firmware" directory or the link below:
   https://github.com/savesabanal01/Mobiflight-LED_Trim_Indicator/tree/Trim_Indicator/firmware
5. Configure an Output config in Mobiflight connector using the firmware and the appropriate trim indicator variable/dataref from MSFS or X Plane. The value of the trim indicator variable should be between -1 an 1.
6. Run Mobiflight Connector and test it out!


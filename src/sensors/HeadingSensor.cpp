#include "HeadingSensor.h"
#include <Arduino.h>

HeadingData HeadingSensor::read()
{
    HeadingData hdg;
    hdg.timestamp_ms = millis();
    hdg.heading_deg  = fmod( millis() / 50.0, 360.0 );   // spin once per 18 s
    return hdg;
}
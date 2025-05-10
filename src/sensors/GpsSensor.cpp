#include "GpsSensor.h"
#include <Arduino.h>

GPSData GpsSensor::read()
{
    static double lat  = 50.0;
    static double lon  = 0.0;
    static float  spd  = 0.0;
    static float  crs  = 90.0;

    // Simple synthetic walk – increment lon each call
    lon += 0.0001;
    spd = 2.0 + 0.5 * sin( millis() / 5000.0 );

    GPSData fix;
    fix.timestamp_ms = millis();
    fix.lat_deg      = lat;
    fix.lon_deg      = lon;
    fix.course_deg   = crs;
    fix.speed_knots  = spd;
    return fix;
}
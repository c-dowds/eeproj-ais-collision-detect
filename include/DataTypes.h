#pragma once
#include <stdint.h>

struct GPSData {
    uint32_t timestamp_ms;   // millis() when sample taken
    double   lat_deg;        // degrees N
    double   lon_deg;        // degrees E
    float    course_deg;     // course‑over‑ground
    float    speed_knots;    // speed‑over‑ground
};

struct HeadingData {
    uint32_t timestamp_ms;
    float    heading_deg;    // 0‑360°
};
#pragma once
#include <Arduino.h>

class AlertManager {
public:
    void sendAlert( const String &msg );
};

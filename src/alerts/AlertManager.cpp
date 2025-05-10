#include "AlertManager.h"

void AlertManager::sendAlert( const String &msg )
{
    Serial.print("[ALERT] ");
    Serial.println( msg );
}
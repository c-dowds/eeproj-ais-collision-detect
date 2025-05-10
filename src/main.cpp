#include <Arduino.h>
#include <FreeRTOS.h>
#include <queue.h>
#include "DataTypes.h"
#include "sensors/GpsSensor.h"
#include "sensors/HeadingSensor.h"
#include "alerts/AlertManager.h"

// Global (for demo) – pass data between tasks via queues
static QueueHandle_t gpsQueue;
static QueueHandle_t headingQueue;

// Instantiate driver stubs (use these to simulate interactions with peripherals on the main platform like GPS,IMU and SatComms Modem)
static GpsSensor     gps;
static HeadingSensor heading;
static AlertManager  alerter;

//declare all functions here
void vTaskGpsReader( void * );
void vTaskHeadingReader( void * );
void vTaskCollisionChecker( void * );



//--------------------------------------------------------------------------//
// Arduino setup() – create RTOS objects
//--------------------------------------------------------------------------//
void setup()
{
    Serial.begin(115200);
    while(!Serial) { }
    Serial.println("\n[BOOT] AIS Collision‑Avoidance Prototype\n");

    // Queues hold latest sample only → length = 1, item = struct
    gpsQueue     = xQueueCreate( 1, sizeof(GPSData) );
    headingQueue = xQueueCreate( 1, sizeof(HeadingData) );

    // Create FreeRTOS tasks with sensible stack & priority
    xTaskCreate( vTaskGpsReader,      "GPS",      256, NULL, 2, NULL );
    xTaskCreate( vTaskHeadingReader,  "HDG",  256, NULL, 2, NULL );
    xTaskCreate( vTaskCollisionChecker,"COL",    512, NULL, 1, NULL );

    // FreeRTOS starts automatically on Arduino after setup exits
}

void loop() { /* never reached */ }

void vTaskDelayMS(int ms)
{
  vTaskDelay(ms / portTICK_PERIOD_MS);
}

//--------------------------------------------------------------------------//
// Task: read GPS every 250ms and push to queue
//--------------------------------------------------------------------------//
void vTaskGpsReader( void * )
{
    while (1)
    {
        GPSData fix = gps.read();
        xQueueOverwrite( gpsQueue, &fix );           // keep latest only
        vTaskDelayMS(250);
    }
}

//--------------------------------------------------------------------------//
// Task: read Heading every 250 ms and push to queue
//--------------------------------------------------------------------------//
void vTaskHeadingReader( void * )
{
    while (1)
    {
        HeadingData hdg = heading.read();
        xQueueOverwrite( headingQueue, &hdg );
        vTaskDelayMS(200);
    }
}

//--------------------------------------------------------------------------//
// Task: collision checker stub – consumes queues, prints summary, fires alert
//--------------------------------------------------------------------------//
void vTaskCollisionChecker( void * )
{
    // Local copies
    GPSData     myFix    {};
    HeadingData myHeading{};

    while(1)
    {
        // Wait (block) until new messages present
        xQueueReceive( gpsQueue,     &myFix,     portMAX_DELAY );
        xQueueReceive( headingQueue, &myHeading, 0 ); // non‑block if none

        // Fake logic: trigger alert if speed > 3 kt (demo!)
        if( myFix.speed_knots > 3.0f )
        {
            alerter.sendAlert( String("Speed high: ") + myFix.speed_knots + " kt" );
        }
    }
}

# AIS-Collision-Avoidance Starter Skeleton
*Arduino + FreeRTOS*  

A minimal, well-structured template that shows how to:

* schedule periodic **FreeRTOS** tasks (`GPS`, `Heading`, `CollisionChecker`);
* pass data between tasks with RTOS queues;
* wrap peripherals in clean **C++ classes** (`GpsSensor`, `HeadingSensor`, `AlertManager`);
* keep `main.cpp` almost declarative while the real work lives in modules;
* build everything with **PlatformIO**.


### Directory structure

```text
eeproj-ais-collision-detect/
├─ platformio.ini        ← board + libraries + build flags
├─ include/              ← public headers
│   ├─ DataTypes.h
│   └─ FreeRTOSConfig.h   (optional)
├─ src/                  ← firmware source
│   ├─ main.cpp
│   ├─ sensors/
│   │   ├─ GpsSensor.h
│   │   ├─ GpsSensor.cpp
│   │   ├─ HeadingSensor.h
│   │   └─ HeadingSensor.cpp
│   ├─ alerts/
│   │   ├─ AlertManager.h
│   │   └─ AlertManager.cpp
│   └─ tasks/            ← project logic modules
│       └─ ReadAis.cpp   (example)
├─ lib/                  ← third-party libraries, if any
└─ tools/                ← host-side Python (AIS log replay, etc.)

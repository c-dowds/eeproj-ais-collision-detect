# AIS-Collision-Avoidance Starter Skeleton
*Arduino + FreeRTOS*  

A minimal, well-structured template that shows how to:

* schedule periodic **FreeRTOS** tasks (`GPS`, `Heading`, `CollisionChecker`);
* pass data between tasks with RTOS queues;
* wrap peripherals in clean **C++ classes** (`GpsSensor`, `HeadingSensor`, `AlertManager`);
* keep `main.cpp` almost declarative while the real work lives in modules;
* build everything with **PlatformIO**.


Directory Structure

eeproj-ais-collision-detect/
├─ platformio.ini        ← board + libraries + build flags
├─ include/              ← public headers
│    ├─ DataTypes.h
│    └─ (optional) FreeRTOSConfig.h 
├─ src/                  ← firmware source
│    ├─ main.cpp
│    ├─ sensors/
│    │    ├─ GpsSensor.h / .cpp
│    │    └─ HeadingSensor.h / .cpp
│    ├─ alerts/
│    │    └─ AlertManager.h / .cpp
│    └─ tasks/           ← your project logic, create multiple modules here
│         └─ e.g ReadAis.cpp
├─ lib/                  ← third-party libs, if any
└─ tools/                ← for Python tools(AIS log replay, etc.)

// Developer ID: 220201047
#include "SecuritySystem.h"
#include "Alarm.h"
#include "Light.h"
#include <iostream>

SecuritySystem::SecuritySystem(Alarm* alarmDevice, std::vector<Light*>* lightDevices)
    : isActive(false), alarm(alarmDevice), lights(lightDevices) {
}

SecuritySystem::~SecuritySystem() {}

void SecuritySystem::activate() {
    isActive = true;
    std::cout << "[SECURITY] Security system ACTIVATED." << std::endl;
}

void SecuritySystem::deactivate() {
    isActive = false;
    if (alarm) alarm->stop();
    std::cout << "[SECURITY] Security system DEACTIVATED." << std::endl;
}

bool SecuritySystem::isActivated() const {
    return isActive;
}

void SecuritySystem::handleMotionDetection() {
    std::cout << "[SECURITY] Motion detected by camera!" << std::endl;
    triggerSecuritySequence();
}

void SecuritySystem::triggerSecuritySequence() {
    if (!isActive) {
        std::cout << "[SECURITY] Security system is not active. Sequence not triggered." << std::endl;
        return;
    }

    std::cout << "\n>>> (BAD VERSION) Running hard-coded security steps...\n";

    // 1) Alarm
    std::cout << ">>> SECURITY: Triggering ALARM..." << std::endl;
    if (alarm) alarm->ring();

    // 2) Light
    std::cout << ">>> SECURITY: Turning ON all lights..." << std::endl;
    if (lights) {
        for (size_t i = 0; i < lights->size(); ++i) {
            (*lights)[i]->powerOn();
            (*lights)[i]->setBrightness(100);
        }
    }

    // 3) Police
    std::cout << ">>> SECURITY: CALLING POLICE..." << std::endl;
    std::cout << ">>> [SIMULATED] Police call initiated!" << std::endl;

    std::cout << "\n[SECURITY] Sequence completed.\n";
}

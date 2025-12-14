// Developer ID: 220201047
#ifndef SECURITYSYSTEM_H
#define SECURITYSYSTEM_H

#include <vector>
#include <string>

class Alarm;
class Light;

class SecuritySystem {
private:
    bool isActive;
    Alarm* alarm;
    std::vector<Light*>* lights;

public:
    SecuritySystem(Alarm* alarmDevice, std::vector<Light*>* lightDevices);
    ~SecuritySystem();

    void activate();
    void deactivate();
    bool isActivated() const;

    void handleMotionDetection();     // Motion Detected -> Security sequence
    void triggerSecuritySequence();   // Alarm -> Light -> Police (hard-coded)
};

#endif // SECURITYSYSTEM_H

#ifndef ALARM_H
#define ALARM_H

#include "Device.h"
#include <string>

// Singleton Pattern - Alarm is a single device that cannot be updated
class Alarm : public Device {
private:
    static Alarm* instance;
    bool isRinging;
    int volumeLevel;  // 0-100
    
    // Private constructor for Singleton
    Alarm();
    Alarm(const Alarm&);  // No copy
    Alarm& operator=(const Alarm&);  // No assignment

public:
    static Alarm* getInstance();
    virtual ~Alarm();

    // Override powerOff - Alarm is critical
    void powerOff();

    virtual void doPowerOn();
    virtual void doPowerOff();
    virtual std::string getDeviceType() const;
    virtual std::string getStatus() const;
    virtual Device* clone() const;  // Returns same instance

    // Alarm-specific methods
    void ring();
    void stop();
    bool isAlarmRinging() const;
    void setVolume(int vol);
    int getVolume() const;
};

#endif // ALARM_H

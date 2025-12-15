/**
 * @file Detector.h
 * @brief Abstract base class for all detector devices
 * @version 5.0
 * @date 03/12/2025
 * 
 * @authors
 * - 220208041: Detectors & Alarm - Logic for devices that cannot be powered off
 * 
 * @patterns Template Method (override)
 */

#ifndef DETECTOR_H
#define DETECTOR_H

#include "Device.h"
#include <string>

class Detector : public Device {
protected:
    bool detected;
    int sensitivityLevel;
    
public:
    Detector(const std::string& brand, const std::string& model);
    virtual ~Detector();
    
    // Override template method steps
    virtual void doPowerOn();
    virtual void doPowerOff();
    
    // Override base methods
    virtual std::string getStatus() const;
    virtual void copyConfigurationFrom(const Device* other);
    
    virtual void powerOff(); // LLR14: Critical devices cannot be powered off
    
    virtual void trigger() = 0;
    virtual void reset();
    void resetDetection(); // Added back
    
    bool isDetected() const;
    void setSensitivity(int level);
    int getSensitivity() const;
};

#endif // DETECTOR_H

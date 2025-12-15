/**
 * @file GasDetector.h
 * @brief Concrete Gas Detector implementation
 * @version 5.0
 * @date 03/12/2025
 * 
 * @authors
 * - 220208041: Detectors & Alarm - Gas Detector implementation
 * 
 * @patterns Factory Method (Product)
 */

#ifndef GASDETECTOR_H
#define GASDETECTOR_H

#include "Detector.h"

// Base Gas Detector class
class GasDetector : public Detector {
protected:
    int gasLevel;      // 0-100 percentage (CO, natural gas, etc.)
    std::string gasType;

public:
    GasDetector(const std::string& brand, const std::string& model);
    virtual ~GasDetector();

    virtual std::string getDeviceType() const;
    virtual std::string getStatus() const;
    virtual Device* clone() const = 0;
    virtual void detect();
    virtual void trigger(); // Override pure virtual
    
    int getGasLevel() const;
    void setGasLevel(int level);  // For simulation
    std::string getGasType() const;
};

// Concrete Gas Detector - Nest CO Detector
class NestGasDetector : public GasDetector {
public:
    NestGasDetector();
    virtual ~NestGasDetector();
    virtual Device* clone() const;
};

// Concrete Gas Detector - Kidde
class KiddeGasDetector : public GasDetector {
public:
    KiddeGasDetector();
    virtual ~KiddeGasDetector();
    virtual Device* clone() const;
};

#endif // GASDETECTOR_H

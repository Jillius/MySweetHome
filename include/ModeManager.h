/**
/**
 * @authors
 * - 220201023: Mode System - State Pattern Implementation
 * 
 * @patterns State (Context)
 */


#ifndef MODEMANAGER_H
#define MODEMANAGER_H

#include <vector>
#include <string>

// Forward declarations
class Device;
class Light;
class Television;
class SoundSystem;

// In V1-V2 implementation, this manages the state logic directly or via simplified states
class ModeManager {
private:
    std::string currentMode;

public:
    ModeManager();
    ~ModeManager();

    void setMode(char choice);
    void applyMode(std::vector<Device*>& lights, 
                   std::vector<Device*>& tvs, 
                   std::vector<Device*>& sounds);
    
    std::string getCurrentModeName() const;
    void displayCurrentMode() const;
};

#endif // MODEMANAGER_H
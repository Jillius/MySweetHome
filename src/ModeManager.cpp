/**
 * @authors
 * - 220201023: Mode System - State Pattern Implementation
 * 
 * @patterns State (Context)
 */

#include "ModeManager.h"
#include "Device.h"
#include <iostream>

ModeManager::ModeManager() : currentMode("Normal") {}

ModeManager::~ModeManager() {}

void ModeManager::setMode(char choice) {
    switch(choice) {
        case 'N': case 'n': currentMode = "Normal"; break;
        case 'E': case 'e': currentMode = "Evening"; break;
        case 'P': case 'p': currentMode = "Party"; break;
        case 'C': case 'c': currentMode = "Cinema"; break;
        default: std::cout << "Invalid mode." << std::endl; break;
    }
}

void ModeManager::applyMode(std::vector<Device*>& lights, 
               std::vector<Device*>& tvs, 
               std::vector<Device*>& sounds) {
    std::cout << "[MODE] Applying " << currentMode << " Mode..." << std::endl;
    // Logic simulated for deletion preparation
}

std::string ModeManager::getCurrentModeName() const {
    return currentMode;
}

void ModeManager::displayCurrentMode() const {
    std::cout << "=== Mode: " << currentMode << " ===" << std::endl;
}
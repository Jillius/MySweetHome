#include "DeviceFactory.h"

// Samsung Factory Implementation
Light* SamsungFactory::createLight() {
    // Samsung doesn't make consumer lights, use Philips instead
    return new PhilipsHueLight();
}

Camera* SamsungFactory::createCamera() {
    return new SamsungCamera();
}

Television* SamsungFactory::createTV() {
    return new SamsungTV();
}

SoundSystem* SamsungFactory::createSoundSystem() {
    // Samsung sound bars - use Bose as equivalent
    return new BoseSoundSystem();
}

// Premium Factory Implementation
Light* PremiumFactory::createLight() {
    return new PhilipsHueLight();
}

Camera* PremiumFactory::createCamera() {
    return new XiaomiCamera();
}

Television* PremiumFactory::createTV() {
    return new LGTV();
}

SoundSystem* PremiumFactory::createSoundSystem() {
    return new SonosSoundSystem();
}

// Nest Detector Factory Implementation
SmokeDetector* NestDetectorFactory::createSmokeDetector() {
    return new NestSmokeDetector();
}

GasDetector* NestDetectorFactory::createGasDetector() {
    return new NestGasDetector();
}

// Budget Detector Factory Implementation
SmokeDetector* BudgetDetectorFactory::createSmokeDetector() {
    return new FirstAlertSmokeDetector();
}

GasDetector* BudgetDetectorFactory::createGasDetector() {
    return new KiddeGasDetector();
}

// Simple Device Factory Implementation
Device* SimpleDeviceFactory::createDevice(DeviceType type) {
    switch (type) {
        case LIGHT_PHILIPS:
            return new PhilipsHueLight();
        case LIGHT_IKEA:
            return new IKEATradfriLight();
        case CAMERA_SAMSUNG:
            return new SamsungCamera();
        case CAMERA_XIAOMI:
            return new XiaomiCamera();
        case TV_SAMSUNG:
            return new SamsungTV();
        case TV_LG:
            return new LGTV();
        case SOUND_SONOS:
            return new SonosSoundSystem();
        case SOUND_BOSE:
            return new BoseSoundSystem();
        case SMOKE_NEST:
            return new NestSmokeDetector();
        case SMOKE_FIRSTALERT:
            return new FirstAlertSmokeDetector();
        case GAS_NEST:
            return new NestGasDetector();
        case GAS_KIDDE:
            return new KiddeGasDetector();
        default:
            return NULL;
    }
}

Device* SimpleDeviceFactory::createDeviceByInput(char deviceChar, int brandChoice) {
    switch (deviceChar) {
        case 'L':
        case 'l':
            return (brandChoice == 1) ? 
                static_cast<Device*>(new PhilipsHueLight()) : 
                static_cast<Device*>(new IKEATradfriLight());
        case 'C':
        case 'c':
            return (brandChoice == 1) ? 
                static_cast<Device*>(new SamsungCamera()) : 
                static_cast<Device*>(new XiaomiCamera());
        case 'T':
        case 't':
            return (brandChoice == 1) ? 
                static_cast<Device*>(new SamsungTV()) : 
                static_cast<Device*>(new LGTV());
        case 'S':
        case 's':
            return (brandChoice == 1) ? 
                static_cast<Device*>(new SonosSoundSystem()) : 
                static_cast<Device*>(new BoseSoundSystem());
        case 'D':
        case 'd':
            // Detectors come as a pair - this returns smoke detector
            // Gas detector should be added separately
            return (brandChoice == 1) ? 
                static_cast<Device*>(new NestSmokeDetector()) : 
                static_cast<Device*>(new FirstAlertSmokeDetector());
        default:
            return NULL;
    }
}

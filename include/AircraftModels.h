#pragma once
#include "Aircraft.h"

using namespace std;

// Constants here are hardcoded for each subclass.
// This will mostly be changed to make it in such a way that 
// the information will be loaded from a config file.
// This way, no need to recompile everytime a spec change is done.

class AlphaAircraft : public Aircraft{
    public:
        std::string companyName() const override {return "Alpha Company";}
        double cruiseSpeedMph() const override {return 120;}
        double batteryCapacityKwh() const override {return 320;}
        double timeToChargeHours() const override {return 0.60;}
        double energyUseKwhPerMile() const override {return 1.6;}
        int passengerCount() const override { return 4;}
        double faultProbabilityPerHour() const override { return 0.25;}
};


class BravoAircraft : public Aircraft {
public:
    std::string companyName() const override { return "Bravo Company";}
    double cruiseSpeedMph() const override { return 100;}
    double batteryCapacityKwh() const override { return 100;}
    double timeToChargeHours() const override { return 0.20;}
    double energyUseKwhPerMile() const override { return 1.5;}
    int passengerCount() const override { return 5;}
    double faultProbabilityPerHour() const override { return 0.10;}
};

class CharlieAircraft : public Aircraft {
public:
    std::string companyName() const override { return "Charlie Company"; }
    double cruiseSpeedMph() const override { return 160; }
    double batteryCapacityKwh() const override { return 220; }
    double timeToChargeHours() const override { return 0.80; }
    double energyUseKwhPerMile() const override { return 2.2; }
    int passengerCount() const override { return 3; }
    double faultProbabilityPerHour() const override { return 0.05; }
};

class DeltaAircraft : public Aircraft {
public:
    std::string companyName() const override { return "Delta Company"; }
    double cruiseSpeedMph() const override { return 90; }
    double batteryCapacityKwh() const override { return 120; }
    double timeToChargeHours() const override { return 0.62; }
    double energyUseKwhPerMile() const override { return 0.8; }
    int passengerCount() const override { return 2; }
    double faultProbabilityPerHour() const override { return 0.22; }
};

class EchoAircraft : public Aircraft {
public:
    std::string companyName() const override { return "Echo Company"; }
    double cruiseSpeedMph() const override { return 30; }
    double batteryCapacityKwh() const override { return 150; }
    double timeToChargeHours() const override { return 0.30; }
    double energyUseKwhPerMile() const override { return 5.8; }
    int passengerCount() const override { return 2; }
    double faultProbabilityPerHour() const override { return 0.61; }
};


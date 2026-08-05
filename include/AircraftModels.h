#pragma once
#include "Aircraft.h"

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
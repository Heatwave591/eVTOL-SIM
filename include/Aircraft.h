#pragma once
#include <string>


struct Aircraft{
    std::string companyName;
    double cruiseSpeedMph;
    double batteryCapacityKwh;
    double timeToChargeHours;
    double energyUseKwhPerMile;
    int passengerCount;
    double faultProbablityPerHour;
};



#include <iostream>
#include "Aircraft.h"

int main(){
    Aircraft alpha{"Alpha Company", 120, 320, 0.60, 1.6, 4, 0.25};

    double flightDurationHours = alpha.batteryCapacityKwh / (alpha.energyUseKwhPerMile * alpha.cruiseSpeedMph);
    double flightDistanceMiles = alpha.cruiseSpeedMph * flightDurationHours;

    std::cout << alpha.companyName << ": "
              << flightDurationHours << " hr, "
              << flightDistanceMiles << " mi\n";
              
    return 0;
}
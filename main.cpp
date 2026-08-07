#include <iostream>
#include "AircraftModels.h"
#include "Vehicle.h"
#include <memory>
#include "AircraftFactory.h"

int main(){
    // std::unique_ptr<Aircraft> alpha = std::make_unique<AlphaAircraft>();


    // std::cout << alpha->companyName() << ": "
    //           << alpha->flightDurationHours() << " hr, "
    //           << alpha->flightDistanceMiles() << " mi\n";

    Vehicle v(0, AircraftFactory::create(AircraftType::Alpha));

    std::cout << v.aircraft().companyName() << ": "
              << v.aircraft().flightDurationHours() << "hrs, "
              << v.aircraft().flightDistanceMiles() << "mi\n";

    return 0;
}

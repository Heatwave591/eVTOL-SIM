#include <iostream>
#include "AircraftModels.h"
#include <memory>

int main(){
    std::unique_ptr<Aircraft> alpha = std::make_unique<AlphaAircraft>();

    std::cout << alpha->companyName() << ": "
              << alpha->flightDurationHours() << " hr, "
              << alpha->flightDistanceMiles() << " mi\n";

    return 0;
}
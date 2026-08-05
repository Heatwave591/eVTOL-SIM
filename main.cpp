#include <iostream>
#include "AircraftModels.h"

int main(){
    Aircraft* alpha = new AlphaAircraft();

    std::cout << alpha->companyName() << ": "
              << alpha->flightDurationHours() << " hr, "
              << alpha->flightDistanceMiles() << " mi\n";

    delete alpha;
    return 0;
}
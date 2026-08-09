#include <iostream>
#include <vector>
#include <memory>
#include "Simulation.h"
#include "AircraftFactory.h"
#include "RandomProvider.h"

using namespace std;

int failures = 0;

void check(bool condition, const string& testName) {
    if (condition) {
        cout << "PASSED: " << testName << "\n";
    } else {
        cout << "FAILED: " << testName << "\n";
        failures++;
    }
}

int main(){
    RandomProvider rng;
    vector<unique_ptr<Vehicle>>vehicles;
    vehicles.push_back(make_unique<Vehicle>(0, AircraftFactory::create(AircraftType::Bravo)));

    Simulation sim(move(vehicles), 1, 3.0, rng);
    sim.run();

    const auto& stats = sim.vehicles()[0]->stats();
    check(stats.flightCount >= 1, "Vehicle completes at least one flight in 3 hours");
    check(stats.totalFlightHours > 0.0, "Recorded flight hours are positive");

    if (failures == 0) {
        cout << "\nAll tests passed!\n";
    } else {
        cout << "\n" << failures << " test(s) failed.\n";
    }
    return failures;

}
#include <iostream>
#include <vector>
#include <memory>
#include "Simulation.h"
#include "AircraftFactory.h"
#include "RandomProvider.h"

using namespace std;

int main(){
    RandomProvider rng;
    vector<unique_ptr<Vehicle>>vehicles;
    vehicles.push_back(make_unique<Vehicle>(0, AircraftFactory::create(AircraftType::Bravo)));

    Simulation sim(move(vehicles), 1, 3.0, rng);
    sim.run();

    return 0;
}
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include "AircraftFactory.h"
#include "Vehicle.h"
#include "Simulation.h"
#include "SimulationStatistics.h"
#include "RandomProvider.h"

using namespace std;

namespace {
constexpr int totalVehicles_inv = 20;
constexpr int chargerCount_inv = 3;
constexpr double simulationHours_inv = 3.0;
}


int main(){

    RandomProvider rng;
    vector<unique_ptr<Vehicle>> vehicles;

    vehicles.reserve(totalVehicles_inv);

    for(int id = 0; id < totalVehicles_inv; ++id){
        AircraftType type = AircraftFactory::randomType(rng);
        vehicles.push_back(make_unique<Vehicle>(id, AircraftFactory::create(type)));
    }

    Simulation sim(move(vehicles), chargerCount_inv, simulationHours_inv, rng);
    sim.run();

    auto report = SimulationStatistics::aggregateByCompany(sim.vehicles());

    for(const auto& r : report){
        cout << r.CompanyName << " ; "
             << "Count: " << r.VehicleCount << " ; "
             << "AvgFlt(hr): " << r.avgFlightTimeHours << " ; "
             << "AvgDist(mi): " << r.avgDistanceMiles << " ; "
             << "AvgChg(hr): " << r.avgChargeTimeHours << " ; "
             << "Faults: " << r.totalFaults << " ; "
             << "PaxMiles: " << r.totalPassengerMiles << "\n";
    }
};
    
    


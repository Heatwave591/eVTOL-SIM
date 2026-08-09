#pragma once
#include <string>
#include <map>
#include <vector>
#include "Vehicle.h"

using namespace std;

struct AggregatedStats{

    string CompanyName;
    int VehicleCount = 0;
    double avgFlightTimeHours = 0;
    double avgDistanceMiles = 0;
    double avgChargeTimeHours = 0;
    int totalFaults = 0;
    double totalPassengerMiles = 0;

};

class SimulationStatistics{
public:
    static vector<AggregatedStats> aggregateByCompany(const vector<unique_ptr<Vehicle>>& vehicles) {
        struct Accum {

            int vehicleCount = 0, chargeCount = 0, flightCount = 0, totalFaults = 0;
            double totalFlightHours = 0, totalDistanceMiles = 0;
            double totalChargeHours = 0, totalPassengerMiles = 0;

        };

        map <string, Accum> byCompany;

        for(const auto& v : vehicles){

            auto& acc = byCompany[v->aircraft().companyName()];
            const VehicleStats& s = v->stats();

            acc.vehicleCount++;
            acc.flightCount += s.flightCount;
            acc.totalFlightHours += s.totalFlightHours;
            acc.totalDistanceMiles += s.totalDistanceMiles;
            acc.chargeCount += s.chargeCount;
            acc.totalChargeHours += s.totalChargeHours;
            acc.totalFaults += s.faultCount;
            acc.totalPassengerMiles += s.totalDistanceMiles  * v->aircraft().passengerCount();
        }

    vector<AggregatedStats> result;
    for(auto& [name, acc] : byCompany){
        result.push_back({name, acc.vehicleCount,
                acc.flightCount ? acc.totalFlightHours / acc.flightCount : 0.0,
                acc.flightCount ? acc.totalDistanceMiles / acc.flightCount : 0.0,
                acc.chargeCount ? acc.totalChargeHours / acc.chargeCount : 0.0,
                acc.totalFaults, acc.totalPassengerMiles});
    }

    return result;
    }
};
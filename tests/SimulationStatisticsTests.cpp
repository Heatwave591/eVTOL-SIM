#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "SimulationStatistics.h"
#include "AircraftFactory.h"

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

void testAggregatesTwoVehiclesSameCompany() {
    vector<unique_ptr<Vehicle>> vehicles;

    auto v1 = make_unique<Vehicle>(0, AircraftFactory::create(AircraftType::Alpha));
    v1->recordFlightCompleted(1.6667, 200.0);
    v1->recordFaults(1);
    vehicles.push_back(move(v1));

    auto v2 = make_unique<Vehicle>(1, AircraftFactory::create(AircraftType::Alpha));
    v2->recordFlightCompleted(1.6667, 200.0);
    v2->recordFaults(2);
    vehicles.push_back(move(v2));

    auto report = SimulationStatistics::aggregateByCompany(vehicles);

    bool ok = report.size() == 1 &&
              report[0].CompanyName == "Alpha Company" &&
              report[0].VehicleCount == 2 &&
              report[0].totalFaults == 3;
    check(ok, "Two vehicles of the same company aggregate into one row with combined totals");
}

int main() {
    testAggregatesTwoVehiclesSameCompany();

    if (failures == 0) {
        cout << "\nAll tests passed!\n";
    } else {
        cout << "\n" << failures << " test(s) failed.\n";
    }
    return failures;
}
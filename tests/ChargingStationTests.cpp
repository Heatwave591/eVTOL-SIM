#include <iostream>
#include <string>
#include "ChargingStation.h"

using namespace std;

int failures = 0;

void check(bool condition, const string& testName){
    if(condition){
        cout <<"PASSED: "<< testName << "\n";
    }
    else{
        cout <<"FAILED: "<< testName << "\n";
        failures++;
    }
}

void testGrantsUpToCapacityThenQueues(){
    ChargingStation station(3);

    bool ok = station.requestCharger(0) &&
              station.requestCharger(1) &&
              station.requestCharger(2) &&
              !station.requestCharger(3) &&
              station.waitingCount() == 1;
    
    check(ok, "Grants then queues");
}


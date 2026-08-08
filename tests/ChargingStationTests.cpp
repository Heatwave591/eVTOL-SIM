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

void testNeverExceedsCapacity(){

    ChargingStation station(3);

    for(int i = 0; i < 100; ++i){       // make sure availableChargers do not act up
        station.requestCharger(i);
    }

    for(int i = 0; i < 50; ++i){
        station.releaseCharger();
    }

    bool ok = station.availableChargers() <= 3 && station.availableChargers() >= 0;
    check(ok, "Capacity never exceeded");

}

void testReleaseToNextVehicle(){

    ChargingStation station(1);

    station.requestCharger(0);
    station.requestCharger(1);

    auto released = station.releaseCharger();
    bool ok = released && *released == 1;
    check(ok, "Releasing charger gives to next one");

}

void testReleaseWithNoWaiters(){

    ChargingStation station(2);
    station.requestCharger(0);

    auto released = station.releaseCharger();

    check(!released, "empty queue returns null");
}
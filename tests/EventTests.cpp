#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include "Event.h"

using namespace std;

int failures = 0;

void check(bool condition, const string& testName){         // reused from ChargingStationTests.cpp
    if(condition){
        cout <<"PASSED: "<< testName << ": TRUE\n";
    }
    else{
        cout <<"FAILED: "<< testName << ": FALSE\n";
        failures++;
    }
}

void testEventOrdering(){
    priority_queue<Event, vector<Event>, EventComparator> queue;
    queue.push({3.0, EventType::FlightComplete, 0});
    queue.push({1.0, EventType::FlightComplete, 1});
    queue.push({2.0, EventType::FlightComplete, 2});


    Event first = queue.top();
    check(first.time == 1, "earliest event is on top of the queue");
}

int main(){
    testEventOrdering();

    if (failures == 0) {
        cout << "\nAll tests passed!\n";
    } 

    else {
        cout << "\n" << failures << " test(s) failed.\n";
    }

    return failures;
}

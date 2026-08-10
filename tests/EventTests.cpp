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

void testEventOrdering(){                                           // Note that a priority queue is used here/
    priority_queue<Event, vector<Event>, EventComparator> queue;    // This essentially takes a max-heap by default
    queue.push({3.0, EventType::FlightComplete, 0});                // We need the soonest time first, which is the opposite
    queue.push({1.0, EventType::FlightComplete, 1});                // of what is given by the pritority queue.
    queue.push({2.0, EventType::FlightComplete, 2});                // So, I inverted the time counts. whichever arrives later gets
                                                                    // a lower priority in include/Event.h::EventComparator

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

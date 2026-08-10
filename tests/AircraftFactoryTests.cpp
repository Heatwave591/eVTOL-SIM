#include <iostream>
#include <string>
#include "AircraftFactory.h"
#include "RandomProviderToCatchBug.h"

using namespace std;

// All tests are rather straight forward tests that were helpful to catch bugs and corner cases.
// Using something like Catch2 with CMake should be able to provide better insight on the codebase.

int failures = 0;

void check(bool condition, const string& testName) {
    if (condition) {
        cout << "PASSED: " << testName << "\n";
    } else {
        cout << "FAILED: " << testName << "\n";
        failures++;
    }
}

void testRandomTypeStaysInValidRange(){
    
    RandomProviderToCatchBug rng1;
    AircraftType type = AircraftFactory::randomType(rng1);
    check(type != AircraftType::Count, "randomType should not return out of range value");

}

int main(){

     testRandomTypeStaysInValidRange();

    if (failures == 0) {
        cout << "\nAll tests passed!\n";
    } else {
        cout << "\n" << failures << " test(s) failed.\n";
    }
    return failures;
}



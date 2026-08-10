# eVTOL-SIM

A discrete-event simulation of 20 eVTOL aircraft, across 5 companies, sharing 3 chargers over a 3-hour operating window.

## Environment

- OS: Arch Linux (EndeavourOS), kernel 7.1.3-arch1-1
- Compiler: `g++` (GCC) 16.1.1, C++17
- Build tool: none beyond `g++` directly (no CMake/external dependencies)

## Design overview

| Class | Responsibility |
|---|---|
| `Aircraft` (abstract) | Spec accessors + derived flight math (duration/distance) |
| `AlphaAircraft` ... `EchoAircraft` | Each company's constants, via inheritance |
| `AircraftFactory` | Builds an aircraft by type, or picks one at random |
| `IRandomProvider` / `RandomProvider` | Randomness abstraction, injectable for testing |
| `Vehicle` | Runtime instance: owns an `Aircraft`, tracks state + accumulated stats |
| `ChargingStation` | 3-charger pool + FIFO wait queue |
| `Event` / `EventComparator` | Time-ordered event for the simulation's min-heap |
| `Simulation` | Runs the event-driven simulation loop |
| `SimulationStatistics` | Aggregates results by company for reporting |

## Building and running

```bash
g++ -std=c++17 -Wall -Wextra -Iinclude main.cpp -o sim
./sim

## Running Tests
Each test file is a standalone executable with its own main(), built the same way as the simulation itself:

g++ -std=c++17 -Wall -Wextra -Iinclude tests/ChargingStationTests.cpp -o tests/run_tests && ./tests/run_tests
g++ -std=c++17 -Wall -Wextra -Iinclude tests/EventTests.cpp -o tests/run_event_tests && ./tests/run_event_tests
g++ -std=c++17 -Wall -Wextra -Iinclude tests/AircraftFactoryTests.cpp -o tests/aircraft_factory_tests && ./tests/aircraft_factory_tests
g++ -std=c++17 -Wall -Wextra -Iinclude tests/SimulationStatisticsTests.cpp -o tests/stats_tests && ./tests/stats_tests

## Assumptions
- All six spec constants per company are taken verbatim from the assignment's vehicle spec table.
- Charger assignment is FIFO — not specified in the prompt, chosen as the simplest fair policy.
- Faults are modeled as a Poisson process, with rate = faultProbabilityPerHour × flightDurationHours per completed flight. Faults are logged but do not ground the vehicle or add downtime.
- A flight or charge still in progress at the 3-hour cutoff is not counted in the final statistics — only fully completed segments count.
- Each of the 20 vehicles independently picks one of the 5 company types at random (uniform distribution), rather than a fixed partition — satisfying "a random number of each type, totaling 20."

## Sample Output
Alpha Company ; Count: 8 ; AvgFlt(hr): 1.66667 ; AvgDist(mi): 200 ; AvgChg(hr): 0.6 ; Faults: 1 ; PaxMiles: 6400
Bravo Company ; Count: 2 ; AvgFlt(hr): 0.666667 ; AvgDist(mi): 66.6667 ; AvgChg(hr): 0.2 ; Faults: 1 ; PaxMiles: 1666.67
Charlie Company ; Count: 2 ; AvgFlt(hr): 0.625 ; AvgDist(mi): 100 ; AvgChg(hr): 0.8 ; Faults: 0 ; PaxMiles: 1200
Delta Company ; Count: 5 ; AvgFlt(hr): 1.66667 ; AvgDist(mi): 150 ; AvgChg(hr): 0.62 ; Faults: 3 ; PaxMiles: 1500
Echo Company ; Count: 3 ; AvgFlt(hr): 0.862069 ; AvgDist(mi): 25.8621 ; AvgChg(hr): 0.3 ; Faults: 5 ; PaxMiles: 310.345
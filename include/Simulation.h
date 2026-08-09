#pragma once
#include <vector>
#include <memory>
#include <queue>
#include "Vehicle.h"
#include "ChargingStation.h"
#include "Event.h"
#include "IRandomProvider.h"

using namespace std;

class Simulation {
public:
    Simulation(vector<unique_ptr<Vehicle>> vehicles, int chargerCount, double durationHours, IRandomProvider& rng) : vehicles_(move(vehicles)), chargingStation_(chargerCount), durationHours_(durationHours), rng_(rng) {}

    void run() {
        for (auto& v : vehicles_) scheduleFlightComplete(*v, 0.0);

        while (!eventQueue_.empty()) {
            Event event = eventQueue_.top();
            eventQueue_.pop();
            if (event.time > durationHours_) break;
            currentTime_ = event.time;

            Vehicle& v = *vehicles_[event.VehicleId];
            if (event.type == EventType::FlightComplete) handleFlightComplete(v);
            else handleChargeComplete(v);
        }
    }

    const vector<unique_ptr<Vehicle>>& vehicles() const { return vehicles_; }

private:
    void scheduleFlightComplete(Vehicle& v, double startTime) {
        v.setState(VehicleState::Flying);
        eventQueue_.push({startTime + v.aircraft().flightDurationHours(),
                           EventType::FlightComplete, v.id()});
    }

    void handleFlightComplete(Vehicle& v) {
        const Aircraft& a = v.aircraft();
        double duration = a.flightDurationHours();
        v.recordFlightCompleted(duration, a.flightDistanceMiles());

        int faults = rng_.nextPoisson(a.faultProbabilityPerHour() * duration);
        v.recordFaults(faults);

        if (chargingStation_.requestCharger(v.id())) {
            v.setState(VehicleState::Charging);
            eventQueue_.push({currentTime_ + a.timeToChargeHours(),
                               EventType::ChargeComplete, v.id()});
        } else {
            v.setState(VehicleState::WaitingForCharger);
        }
    }

    void handleChargeComplete(Vehicle& v) {
        v.recordChargeCompleted(v.aircraft().timeToChargeHours());
        if (auto nextId = chargingStation_.releaseCharger()) {
            Vehicle& next = *vehicles_[*nextId];
            next.setState(VehicleState::Charging);
            eventQueue_.push({currentTime_ + next.aircraft().timeToChargeHours(),
                               EventType::ChargeComplete, next.id()});
        }
        scheduleFlightComplete(v, 0.0);
    }

    vector<unique_ptr<Vehicle>> vehicles_;
    ChargingStation chargingStation_;
    double durationHours_;
    IRandomProvider& rng_;
    double currentTime_ = 0.0;
    priority_queue<Event, vector<Event>, EventComparator> eventQueue_;
};
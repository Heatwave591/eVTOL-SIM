#pragma once
#include <memory>
#include "Aircraft.h"


enum class VehicleState {ying, WaitingForCharger, Charging};

struct VehicleStats{
    int flightCount = 0;
    double totalFlightHours = 0;
    double totalDistanceMiles = 0;
    int chargeCount = 0;
    double totalChargeHours = 0;
    int faultCount = 0;
};

class Vehicle{
    public:
        Vehicle(int id, std::unique_ptr<Aircraft> aircraft) : id_(id), aircraft_(std::move(aircraft)) {}

        int id() const { return id_; }
        const Aircraft& aircraft() const { return *aircraft_; }
        VehicleState state() const { return state_; }
        void setState(VehicleState s) { state_ = s; }
        const VehicleStats& stats() const { return stats_; }

        void recordFlightCompleted(double durationHours, double distanceMiles){
            stats_.flightCount++;
            stats_.totalFlightHours += durationHours;
            stats_.totalDistanceMiles += distanceMiles;
        }

        void recordChargeCompleted(double durationHours) {
        stats_.chargeCount++;
        stats_.totalChargeHours += durationHours;
    }
    
    void recordFaults(int count) { stats_.faultCount += count; }


    private:
        int id_;
        std::unique_ptr<Aircraft> aircraft_;
        VehicleState state_ = VehicleState::FLying;
        VehicleStats stats_;
};
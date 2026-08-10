#pragma once
#include <queue>
#include <optional>

using namespace std;

class ChargingStation{
public:
    explicit ChargingStation(int chargerCount) : availableChargers_(chargerCount){}

    size_t waitingCount() const { return waitingQueue_.size(); }
    int availableChargers() const { return availableChargers_; }

    bool requestCharger(int vehicleId){     // This is a FIFO buffer... 
        if(availableChargers_ > 0){         // Using a charge level based priority is more realistic
            --availableChargers_;
            return true;
        }
        waitingQueue_.push(vehicleId);
        return false;
    }

    optional<int> releaseCharger(){
        if(!waitingQueue_.empty()){
            int newVehicle = waitingQueue_.front();
            waitingQueue_.pop();
            return newVehicle;
        }
        ++availableChargers_;
        return nullopt;
    } 


private:
    int availableChargers_;
    queue<int> waitingQueue_;
};
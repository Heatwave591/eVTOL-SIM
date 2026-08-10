#pragma once
#include <string>
#include <utility>
using namespace std;


class Aircraft{
    public:
        virtual ~Aircraft() = default;

        virtual string companyName() const = 0;
        virtual double cruiseSpeedMph() const = 0;
        virtual double batteryCapacityKwh() const = 0;
        virtual double timeToChargeHours() const = 0;
        virtual double energyUseKwhPerMile() const = 0;
        virtual int passengerCount() const = 0;
        virtual double faultProbabilityPerHour() const = 0;

        // No need of virtual here because this is same in every class. 
        // Calculating this is done with the virtual getters from the top.
        // So, duplicates won't be made for each class.
        
        double flightDurationHours() const {
        return batteryCapacityKwh() / (energyUseKwhPerMile() * cruiseSpeedMph());
    }
        double flightDistanceMiles() const {
            return cruiseSpeedMph() * flightDurationHours();
    }

};

//class Aircraft{
//    public:
//    Aircraft(std::string companyName, 
//            double cruiseSpeedMph,
//            double batteryCapacityKwh,
//            double timeToChargeHours,
//            double energyUseKwhPerMile,
//            int passengerCount,
//            double faultProbabilityPerHour)
//
//    : companyName_(std::move(companyName)),
//      cruiseSpeedMph_(cruiseSpeedMph),
//      batteryCapacityKwh_(batteryCapacityKwh),
//      timeToChargeHours_(timeToChargeHours),
//      energyUseKwhPerMile_(energyUseKwhPerMile), 
//      passengerCount_(passengerCount), 
//      faultProbabilityPerHour_(faultProbabilityPerHour) {}
//
//      std::string companyName() const { return companyName_; }
//    double cruiseSpeedMph() const { return cruiseSpeedMph_; }
//    double batteryCapacityKwh() const { return batteryCapacityKwh_; }
//    double timeToChargeHours() const { return timeToChargeHours_; }
//    double energyUseKwhPerMile() const { return energyUseKwhPerMile_; }
//    int passengerCount() const { return passengerCount_; }
//    double faultProbabilityPerHour() const { return faultProbabilityPerHour_; }
//
//private:
//    std::string companyName_;
//    double cruiseSpeedMph_;
//    double batteryCapacityKwh_;
//    double timeToChargeHours_;
//    double energyUseKwhPerMile_;
//    int passengerCount_;
//    double faultProbabilityPerHour_;
//};
//

//struct Aircraft{
//    std::string companyName;
//    double cruiseSpeedMph;
//    double batteryCapacityKwh;
//    double timeToChargeHours;
//    double energyUseKwhPerMile;
//    int passengerCount;
//    double faultProbablityPerHour;
//};



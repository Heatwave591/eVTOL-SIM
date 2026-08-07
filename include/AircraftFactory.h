#pragma once
#include "AircraftModels.h"
#include <stdexcept>
#include <memory>


enum class AircraftType{Alpha, Bravo, Charlie, Delta, Echo, Count};

class AircraftFactory{
public:
    static std::unique_ptr<Aircraft> create(AircraftType type){
        switch (type){
            case AircraftType::Alpha : return std::make_unique<AlphaAircraft>();
            case AircraftType::Bravo : return std::make_unique<BravoAircraft>();
            case AircraftType::Charlie : return std::make_unique<CharlieAircraft>();
            case AircraftType::Delta : return std::make_unique<DeltaAircraft>();
            case AircraftType::Echo : return std::make_unique<EchoAircraft>();
            case AircraftType::Count : break;
        }

        throw std::invalid_argument("Unknown aircraft type");
    }
};
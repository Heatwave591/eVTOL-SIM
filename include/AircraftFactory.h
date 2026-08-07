#pragma once
#include "AircraftModels.h"
#include <stdexcept>
#include <memory>
using namespace std;


enum class AircraftType{Alpha, Bravo, Charlie, Delta, Echo, Count};

class AircraftFactory{
public:
    static unique_ptr<Aircraft> create(AircraftType type){
        switch (type){
            case AircraftType::Alpha : return make_unique<AlphaAircraft>();
            case AircraftType::Bravo : return make_unique<BravoAircraft>();
            case AircraftType::Charlie : return make_unique<CharlieAircraft>();
            case AircraftType::Delta : return make_unique<DeltaAircraft>();
            case AircraftType::Echo : return make_unique<EchoAircraft>();
            case AircraftType::Count : break;
        }

        throw std::invalid_argument("Unknown aircraft type");
    }
};
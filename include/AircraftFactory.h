#pragma once
#include "AircraftModels.h"
#include <stdexcept>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "IRandomProvider.h"

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

    static AircraftType randomType(IRandomProvider& rng){

        int count = static_cast<int>(AircraftType::Count);
        return static_cast<AircraftType>(rng.nextInt(0, count - 1));
    }
};
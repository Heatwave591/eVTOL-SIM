#pragma once
#include "IRandomProvider.h"
#include <random>

using namespace std;

class RandomProvider : public IRandomProvider{
public:
    explicit RandomProvider(unsigned seed = random_device{}()) : engine_(seed) {}

    int nextInt(int minInclusive, int maxInclusive) override{
        uniform_int_distribution<int> dist(minInclusive, maxInclusive);
        return dist(engine_);
    }

    int nextPoisson(double mean) override {
        if(mean <= 0.0) return 0;
        poisson_distribution<int> dist(mean);
        return dist(engine_);
    }

private:
    mt19937 engine_;
};
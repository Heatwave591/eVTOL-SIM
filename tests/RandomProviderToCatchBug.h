#pragma once
#include "IRandomProvider.h"

using namespace std;

class RandomProviderToCatchBug : public IRandomProvider{
public:
    int nextInt(int minInclusive, int maxInclusive) override { return maxInclusive; };
    int nextPoisson(double) override { return 0; };

};
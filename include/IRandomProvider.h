#pragma once

class IRandomProvider{
public:
    virtual ~IRandomProvider() = default;
    virtual int nextInt(int minInclusive, int maxInclusive) = 0;
    virtual int nextPoisson(double mean) = 0;

};
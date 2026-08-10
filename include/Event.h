#pragma once

enum class EventType {FlightComplete, ChargeComplete};

struct Event{
    double time;
    EventType type;
    int VehicleId;
};

// a must be greate than b. written details in EventTests.cpp
struct EventComparator{
    bool operator()(const Event& a, const Event& b) const { return a.time > b.time; };
};

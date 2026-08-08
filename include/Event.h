#pragma once

enum class EventType {FlightComplete, ChargeComplete};

struct Event{
    double time;
    EventType type;
    int VehicleId;
};

struct EventComparator{
    bool operator()(const Event& a, const Event& b) const { return a.time > b.time; };
};

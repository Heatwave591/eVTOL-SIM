#pragma once

enum class EventType {FightComplete, ChargeComplete};

struct Event{
    double time;
    EventType type;
    int VehicleId;
};

struct EventComparator{
    bool operator()(const Event& a, Event& b) const { return a.time < b.time; };
};

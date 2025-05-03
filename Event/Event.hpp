#pragma once
#include <EventType.hpp>
#include <Time.hpp>

class Event
{
    protected:
        Time time;
        EventType id;
        Event(Time time=Time(), EventType id=EventType::end) : time(time), id(id) {}
};

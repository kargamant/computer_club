#pragma once
#include <EventType.hpp>
#include <Time.hpp>

class EventHandler;

class BaseEvent
{
    protected:
        Time time;
        EventType id;
        BaseEvent(Time time=Time(), EventType id=EventType::end) : time(time), id(id) {}
    public:
        virtual ~BaseEvent() {}
        virtual void accept(EventHandler& handler)=0;
};

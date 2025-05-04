#pragma once
#include <EventType.hpp>
#include <Time.hpp>
#include <EventConfig.hpp>

class EventHandler;

class BaseEvent
{
    protected:
        Time time;
        EventType id;
        BaseEvent(Time time=Time(), EventType id=EventType::end) : time(time), id(id) {}
    public:
        EventType getType() {return id;}
        virtual ~BaseEvent() {}
        virtual EventConfig accept(EventHandler& handler)=0;
        virtual std::string get_formatted();
};

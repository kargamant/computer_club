#include <EventType.hpp>
#include <Time.hpp>

class Event
{
    private:
        Time time;
        EventType id;
    protected:
        Event(Time time, EventType id) : time(time), id(id) {}
};

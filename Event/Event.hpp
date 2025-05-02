#include <EventType.hpp>

class Event
{
    private:
        int time;
        EventType id;
    protected:
        Event(int time, EventType id) : time(time), id(id) {}
};

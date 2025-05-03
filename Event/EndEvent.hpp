#include <Event.hpp>
#include <Time.hpp>
#include <EventConfig.hpp>

class EventFactory;

class EndEvent : public Event
{
    public:
        EndEvent() : Event({-1, -1}, EventType::end) {}
        EndEvent(const EventConfig& config) : Event({-1, -1}, EventType::end) {}
};
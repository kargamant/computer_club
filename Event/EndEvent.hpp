#include <Event.hpp>

class EndEvent : public Event
{
    public:
        EndEvent() : Event(-1, EventType::end) {}
};
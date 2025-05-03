#include <Event.hpp>
#include <Time.hpp>

class EndEvent : public Event
{
    public:
        EndEvent() : Event({-1, -1}, EventType::end) {}
};
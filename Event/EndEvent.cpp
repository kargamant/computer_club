#include <EndEvent.hpp>
#include <EventHandler.hpp>

std::ostream& operator<<(std::ostream& st, const EndEvent& event)
{
    st << "EndEvent:" << std::endl;
    st << "time: " << event.time << std::endl;
    st << "id: " << event.id << std::endl;

    return st;
}

void EndEvent::accept(EventHandler& handler)
{
    handler.handle(this);
}
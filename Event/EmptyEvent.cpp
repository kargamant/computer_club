#include <EmptyEvent.hpp>
#include <EventHandler.hpp>

std::ostream& operator<<(std::ostream& st, const EmptyEvent& event)
{
    st << "EmptyEvent:" << std::endl;
    st << "time: " << event.time << std::endl;
    st << "id: " << event.id << std::endl;

    return st;
}

void EmptyEvent::accept(EventHandler& handler)
{
    handler.handle(this);
}
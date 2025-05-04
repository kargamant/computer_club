#include <InfoEvent.hpp>
#include <EventHandler.hpp>

InfoEvent::InfoEvent(const EventConfig& config)
{
    InfoEventConfig cf = std::get<InfoEventConfig>(config);
    time = cf.time;
    id = cf.id;
}

std::ostream& operator<<(std::ostream& st, const InfoEvent& event)
{
    st << "InfoEvent:" << std::endl;
    st << "time: " << event.time << std::endl;
    st << "id: " << event.id << std::endl;

    return st;
}

EventConfig InfoEvent::accept(EventHandler& handler)
{
    return handler.handle(this);
}
#include <ErrorEvent.hpp>
#include <EventHandler.hpp>

ErrorEvent::ErrorEvent(const EventConfig& config)
{
    ErrorEventConfig cf = std::get<ErrorEventConfig>(config);
    time = cf.time;
    id = cf.id;
    error_message = cf.error_message;
}

std::ostream& operator<<(std::ostream& st, const ErrorEvent& event)
{
    st << "ErrorEvent:" << std::endl;
    st << "time: " << event.time << std::endl;
    st << "id: " << event.id << std::endl;
    st << "error_message: " << event.error_message << std::endl;

    return st;
}

EventConfig ErrorEvent::accept(EventHandler& handler)
{
    return handler.handle(this);
}
#include <ErrorEvent.hpp>

ErrorEvent::ErrorEvent(const EventConfig& config)
{
    ErrorEventConfig cf = std::get<ErrorEventConfig>(config);
    time = cf.time;
    id = cf.id;
    error_message = cf.error_message;
}

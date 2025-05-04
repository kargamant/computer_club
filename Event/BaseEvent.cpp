#include <BaseEvent.hpp>

std::string BaseEvent::get_formatted()
{
    return time.get_formatted() + " " + std::to_string(id);
}

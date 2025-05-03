#include <Event.hpp>
#include <string>
#include <Time.hpp>

class ErrorEvent : public Event
{
    private:
        std::string error_message;
    public:
        ErrorEvent(Time time, EventType id, const std::string& error_message) : Event(time, id), error_message(error_message) {}
};
#include <Event.hpp>
#include <string>

class ErrorEvent : public Event
{
    private:
        std::string error_message;
    public:
        ErrorEvent(int time, EventType id, const std::string& error_message) : Event(time, id), error_message(error_message) {}
};
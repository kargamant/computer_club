#include <Event.hpp>
#include <string>
#include <Time.hpp>
#include <EventConfig.hpp>

class TableEvent : public Event
{
    private:
        std::string client_name;
        int table_number;
    public:
        TableEvent(Time time, EventType id, const std::string& client_name, int table_number) : 
            Event(time, id), 
            client_name(client_name), 
            table_number(table_number) {}
        TableEvent(const EventConfig& config);
};
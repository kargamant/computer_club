#include <Event.hpp>
#include <string>

class ClientEvent : public Event
{
    private:
        std::string client_name;
    public:
        ClientEvent(int time, EventType id, const std::string& client_name) : Event(time, id), client_name(client_name) {}
};


#include <ClientEvent.hpp>
#include <EventHandler.hpp>

ClientEvent::ClientEvent(const EventConfig& config)
{
    ClientEventConfig cf = std::get<ClientEventConfig>(config);
    time = cf.time;
    id = cf.id;
    client_name = cf.client_name;
}

std::ostream& operator<<(std::ostream& st, const ClientEvent& event)
{
    st << "ClientEvent:" << std::endl;
    st << "time: " << event.time << std::endl;
    st << "id: " << event.id << std::endl;
    st << "client_name: " << event.client_name << std::endl;

    return st;
}

void ClientEvent::accept(EventHandler& handler)
{
    handler.handle(this);
}

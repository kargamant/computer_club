#include <ClientEvent.hpp>

ClientEvent::ClientEvent(const EventConfig& config)
{
    ClientEventConfig cf = std::get<ClientEventConfig>(config);
    time = cf.time;
    id = cf.id;
    client_name = cf.client_name;
}
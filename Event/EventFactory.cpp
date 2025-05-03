#include <EventFactory.hpp>
#include <ClientEvent.hpp>
#include <TableEvent.hpp>
#include <ErrorEvent.hpp>
#include <EndEvent.hpp>

// template<>
// std::unique_ptr<Event> EventFactory::alloc_event<ClientEventConfig>(const EventConfig& config)
// {
//     return std::make_unique<ClientEvent>(config);
// }

// template<>
// std::unique_ptr<Event> EventFactory::alloc_event<TableEventConfig>(const EventConfig& config)
// {
//     return std::make_unique<TableEvent>(config);
// }

// template<>
// std::unique_ptr<Event> EventFactory::alloc_event<ErrorEventConfig>(const EventConfig& config)
// {
//     return std::make_unique<ErrorEvent>(config);
// }

// template<>
// std::unique_ptr<Event> EventFactory::alloc_event<EndEventConfig>(const EventConfig& config)
// {
//     return std::make_unique<EndEvent>(config);
// }

std::unique_ptr<Event> EventFactory::create_event(const EventConfig& config)
{
    return alloc_event<decltype(config)>(config);
}


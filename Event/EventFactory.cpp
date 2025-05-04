#include <EventFactory.hpp>
#include <ClientEvent.hpp>
#include <TableEvent.hpp>
#include <ErrorEvent.hpp>
#include <EndEvent.hpp>

std::unique_ptr<BaseEvent> EventFactory::creator_visitor::operator()(const ClientEventConfig& config)
{
    return std::make_unique<ClientEvent>(config);
}

std::unique_ptr<BaseEvent> EventFactory::creator_visitor::operator()(const TableEventConfig& config)
{
    return std::make_unique<TableEvent>(config);
}

std::unique_ptr<BaseEvent> EventFactory::creator_visitor::operator()(const ErrorEventConfig& config)
{
    return std::make_unique<ErrorEvent>(config);
}

std::unique_ptr<BaseEvent> EventFactory::creator_visitor::operator()(const EndEventConfig& config)
{
    return std::make_unique<EndEvent>(config);
}

std::unique_ptr<BaseEvent> EventFactory::create_event(const EventConfig& config)
{
    return std::visit(EventFactory::creator_visitor{}, config);
}


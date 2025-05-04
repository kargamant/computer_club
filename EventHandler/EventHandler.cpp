#include <EventHandler.hpp>
#include <iostream>

void EventHandler::handle(ClientEvent* event)
{
    std::cout << *event;
}

void EventHandler::handle(TableEvent* event)
{
    std::cout << *event;
}

void EventHandler::handle(ErrorEvent* event)
{
    std::cout << *event;
}

void EventHandler::handle(EndEvent* event)
{
    std::cout << *event;
}
#pragma once
#include <BaseEvent.hpp>
#include <string>
#include <Time.hpp>
#include <EventConfig.hpp>
#include <iostream>


class ClientEvent : public BaseEvent
{
    private:
        std::string client_name;
    public:
        ClientEvent(Time time, EventType id, const std::string& client_name) : BaseEvent(time, id), client_name(client_name) {}
        ClientEvent(const EventConfig& config);
        virtual EventConfig accept(EventHandler& handler) override;
        friend std::ostream& operator<<(std::ostream& st, const ClientEvent& event);
        friend EventHandler;
};

std::ostream& operator<<(std::ostream& st, const ClientEvent& event);

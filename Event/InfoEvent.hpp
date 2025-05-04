#pragma once
#include <BaseEvent.hpp>
#include <Time.hpp>
#include <EventConfig.hpp>
#include <iostream>

class InfoEvent : public BaseEvent
{
    public:
        InfoEvent() : BaseEvent({-1, -1}, EventType::empty) {}
        InfoEvent(const EventConfig& config);
        virtual EventConfig accept(EventHandler& handler) override;
        friend std::ostream& operator<<(std::ostream& st, const InfoEvent& event);
        friend EventHandler;
};

std::ostream& operator<<(std::ostream& st, const InfoEvent& event);

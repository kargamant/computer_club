#pragma once
#include <BaseEvent.hpp>
#include <Time.hpp>
#include <EventConfig.hpp>
#include <iostream>

class EmptyEvent : public BaseEvent
{
    public:
        EmptyEvent() : BaseEvent({-1, -1}, EventType::empty) {}
        EmptyEvent(const EventConfig& config) : BaseEvent({-1, -1}, EventType::empty) {}
        virtual void accept(EventHandler& handler) override;
        friend std::ostream& operator<<(std::ostream& st, const EmptyEvent& event);
        friend EventHandler;
};

std::ostream& operator<<(std::ostream& st, const EmptyEvent& event);

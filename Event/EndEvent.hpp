#pragma once
#include <BaseEvent.hpp>
#include <Time.hpp>
#include <EventConfig.hpp>
#include <iostream>

class EndEvent : public BaseEvent
{
    public:
        EndEvent() : BaseEvent({-1, -1}, EventType::end) {}
        EndEvent(const EventConfig& config) : BaseEvent({-1, -1}, EventType::end) {}
        virtual void accept(EventHandler& handler) override;
        friend std::ostream& operator<<(std::ostream& st, const EndEvent& event);
        friend EventHandler;
};

std::ostream& operator<<(std::ostream& st, const EndEvent& event);

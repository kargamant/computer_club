#pragma once
#include <BaseEvent.hpp>
#include <string>
#include <Time.hpp>
#include <EventConfig.hpp>
#include <iostream>


class ErrorEvent : public BaseEvent
{
    private:
        std::string error_message;
    public:
        ErrorEvent(Time time, EventType id, const std::string& error_message) : BaseEvent(time, id), error_message(error_message) {}
        ErrorEvent(const EventConfig& config);
        virtual EventConfig accept(EventHandler& handler) override;
        virtual std::string get_formatted() override;
        friend std::ostream& operator<<(std::ostream& st, const ErrorEvent& event);
        friend EventHandler;
};

std::ostream& operator<<(std::ostream& st, const ErrorEvent& event);
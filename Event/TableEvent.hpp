#pragma once
#include <BaseEvent.hpp>
#include <string>
#include <Time.hpp>
#include <EventConfig.hpp>
#include <iostream>

class TableEvent : public BaseEvent
{
    private:
        std::string client_name;
        int table_number;
    public:
        TableEvent(Time time, EventType id, const std::string& client_name, int table_number) : 
            BaseEvent(time, id), 
            client_name(client_name), 
            table_number(table_number) {}
        TableEvent(const EventConfig& config);
        virtual void accept(EventHandler& handler) override;
        friend std::ostream& operator<<(std::ostream& st, const TableEvent& event);
        friend EventHandler;
};

std::ostream& operator<<(std::ostream& st, const TableEvent& event);

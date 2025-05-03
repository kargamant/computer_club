#pragma once
#include <EventType.hpp>
#include <string>
#include <variant>
#include <Time.hpp>

struct ClientEventConfig
{
    Time time;
    EventType id;
    std::string client_name;

    ClientEventConfig(Time time, EventType id, const std::string& client_name) : time(time), id(id), client_name(client_name) {}
};

struct TableEventConfig
{
    Time time;
    EventType id;
    std::string client_name;
    int table_number;

    TableEventConfig(Time time, EventType id, const std::string& client_name, int table_number) : time(time), id(id), client_name(client_name), table_number(table_number) {}
};

struct ErrorEventConfig
{
    Time time;
    const EventType id = EventType::error;
    std::string error_message;

    ErrorEventConfig(Time time, EventType id, const std::string& error_message) : time(time), id(id), error_message(error_message) {}
};

struct EndEventConfig
{
    Time time{-1, -1};
    const EventType id = EventType::end;
};

using EventConfig = std::variant<ClientEventConfig, TableEventConfig, ErrorEventConfig, EndEventConfig>;
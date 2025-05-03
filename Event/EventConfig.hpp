#include <EventType.hpp>
#include <string>
#include <variant>
#include <Time.hpp>

struct ClientEventConfig
{
    Time time;
    EventType id;
    std::string client_name;
};

struct TableEventConfig
{
    Time time;
    EventType id;
    std::string client_name;
    int table_number;
};

struct ErrorEventConfig
{
    Time time;
    EventType id;
    std::string error_message;
};

struct EndEventConfig
{
    Time time{-1, -1};
    EventType id = EventType::end;
};

using EventConfig = std::variant<ClientEventConfig, TableEventConfig, ErrorEventConfig, EndEventConfig>;

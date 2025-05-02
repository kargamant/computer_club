#include <EventType.hpp>
#include <string>
#include <variant>

struct ClientEventConfig
{
    int time;
    EventType id;
    std::string client_name;
};

struct TableEventConfig
{
    int time;
    EventType id;
    std::string client_name;
    int table_number;
};

struct ErrorEventConfig
{
    int time;
    EventType id;
    std::string error_message;
};

struct EndEventConfig
{
    int time = -1;
    EventType id = EventType::end;
};

using EventConfig = std::variant<ClientEventConfig, TableEventConfig, ErrorEventConfig, EndEventConfig>;

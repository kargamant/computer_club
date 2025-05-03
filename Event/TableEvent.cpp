#include <TableEvent.hpp>

TableEvent::TableEvent(const EventConfig& config)
{
    TableEventConfig cf = std::get<TableEventConfig>(config);
    time = cf.time;
    id = cf.id;
    client_name = cf.client_name;
    table_number = cf.table_number;
}
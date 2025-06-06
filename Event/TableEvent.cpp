#include <TableEvent.hpp>
#include <EventHandler.hpp>

TableEvent::TableEvent(const EventConfig& config)
{
    TableEventConfig cf = std::get<TableEventConfig>(config);
    time = cf.time;
    id = cf.id;
    client_name = cf.client_name;
    table_number = cf.table_number;
}

std::ostream& operator<<(std::ostream& st, const TableEvent& event)
{
    st << "TableEvent:" << std::endl;
    st << "time: " << event.time << std::endl;
    st << "id: " << event.id << std::endl;
    st << "client_name: " << event.client_name << std::endl;
    st << "table_number: " << event.table_number << std::endl;

    return st;
}

EventConfig TableEvent::accept(EventHandler& handler)
{
    return handler.handle(this);
}

std::string TableEvent::get_formatted()
{
    return time.get_formatted() + " " + std::to_string(id) + " " + client_name + " " + std::to_string(table_number);
}
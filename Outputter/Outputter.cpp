#include <Outputter.hpp>

void Outputter::print_event(BaseEvent* event)
{
    *st << event->get_formatted() << std::endl;
}

void Outputter::print_open_time()
{
    *st << club->open_time.get_formatted() << std::endl;
}

void Outputter::print_close_time()
{
    *st << club->close_time.get_formatted() << std::endl;
}

void Outputter::print_table(int table_number)
{
    *st << club->tables[table_number].get_formatted(table_number+1) << std::endl;
}

void Outputter::print_all_tables()
{
    for(int i=0; i<club->n; i++)
        print_table(i);
}

#include <Table.hpp>

void Table::on_client_sit(Time sit_time)
{
    if(start_time.hour == -1 && start_time.minute == -1)
        start_time = sit_time;
    update_time = sit_time;
    is_occupied = true;
}

void Table::on_client_exit(Time exit_time, int checkout_price)
{
    int minutes_played = exit_time.get_in_minutes() - update_time.get_in_minutes();
    int hours_played = minutes_played/60 + minutes_played%60!=0;
    revenue += checkout_price * hours_played;
    is_occupied = false;
    update_time = exit_time;
}

Time Table::get_total_time()
{
    return update_time - start_time;
}

std::string Table::get_formatted(int table_number)
{
    return std::to_string(table_number) + " " + std::to_string(revenue) + " " + get_total_time().get_formatted();
}
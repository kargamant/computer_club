#include <Table.hpp>

void Table::on_client_sit(Time sit_time)
{
    update_time = sit_time;
    is_occupied = true;
}

void Table::on_client_exit(Time exit_time, int checkout_price)
{
    update_time = exit_time;
    int hours_played = exit_time.get_in_minutes() - update_time.get_in_minutes();
    hours_played += hours_played%60!=0;
    revenue += checkout_price * hours_played;
    is_occupied = false;
}
#include <Club.hpp>

Club::Club(int n, Time open_time, Time close_time, int hour_price) : n(n), 
                                                                     open_time(open_time), 
                                                                     close_time(close_time), 
                                                                     hour_price(hour_price),
                                                                     occupied_tables(0)
{
    tables.resize(n);   
}

Club::Club(const ClubConfig& config) : n(config.n),
                                       open_time(config.open_time),
                                       close_time(config.close_time),
                                       hour_price(config.hour_price),
                                       occupied_tables(0)
{
    tables.resize(n);
}

bool Club::isInClub(const std::string& client)
{
    return client_map.contains(client);
}

bool Club::isInTime(Time& time)
{
    return time.get_in_minutes() >= open_time.get_in_minutes() &&
           time.get_in_minutes() <= close_time.get_in_minutes();
}

bool Club::isLineFull()
{
    return wait_line.size() > n;
}

bool Club::isFreeTables()
{
    return occupied_tables < n;
}

void Club::add_client(const std::string& client)
{
    client_map.insert({client, -1});
}

void Club::wait_client(const std::string& client)
{
    wait_line.push(client);
}

int Club::remove_client(Time exit_time, const std::string& client)
{
    if(isInClub(client))
    {
        int table_number = client_map[client];
        if(table_number != -1)
        {
            tables[table_number].on_client_exit(exit_time, hour_price);
            occupied_tables--;
        }
        client_map.erase(client);
        return table_number;
    }
}

std::string Club::get_client_from_line()
{
    if(!wait_line.empty())
    {
        std::string client = wait_line.front();
        wait_line.pop();
        return client;
    }
    return "";
}

void Club::sit_client_table(Time enter_time, const std::string& client, int table_number)
{
    client_map[client] = table_number;
    tables[table_number].on_client_sit(enter_time);
    occupied_tables++;
}
#pragma once
#include <string>
#include <Time.hpp>

class Table
{
    private:
        int revenue;
        Time start_time;
        Time update_time;
        bool is_occupied;
        Time get_total_time();
    public:
        void on_client_sit(Time sit_time);
        void on_client_exit(Time exit_time, int checkout_price);
        bool isOccupied() {return is_occupied;}

        std::string get_formatted(int table_number);
};
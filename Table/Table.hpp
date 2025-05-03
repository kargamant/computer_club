#include <string>
#include <Time.hpp>

class Table
{
    private:
        int revenue;
        Time update_time;
        bool is_occupied;
    public:
        void on_client_sit(Time sit_time);
        void on_client_exit(Time exit_time, int checkout_price);
        bool isOccupied() {return is_occupied;}
};
#include <Club.hpp>

Club::Club(int n, Time open_time, Time close_time, int hour_price) : n(n), 
                                                                     open_time(open_time), 
                                                                     close_time(close_time), 
                                                                     hour_price(hour_price),
                                                                     occupied_tables(0)
{
    tables.resize(n);   
}

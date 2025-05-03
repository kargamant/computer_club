#include <iostream>
#include <Time.hpp>

struct ClubConfig
{
    int n;
    Time open_time;
    Time close_time;
    int hour_price;

    friend void operator<<(std::ostream& st, const ClubConfig& cf);
};

void operator<<(std::ostream& st, const ClubConfig& cf);
#pragma once
#include <string>

struct Time
{
    int hour;
    int minute;

    Time(int hour=-1, int minute=-1) : hour(hour), minute(minute) {}
    int get_in_minutes();
    std::string get_formatted() const;

    Time& operator=(const Time& ntime);
    friend Time operator-(Time& time1, Time& time2);
};

std::ostream& operator<<(std::ostream& st, const Time& time);
Time operator-(Time& time1, Time& time2);
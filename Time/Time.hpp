#pragma once
#include <string>

struct Time
{
    int hour;
    int minute;

    Time(int hour=0, int minute=0) : hour(hour), minute(minute) {}
    int get_in_minutes();
    std::string get_formatted() const;
};
#include <Time.hpp>

int Time::get_in_minutes()
{
    return hour*60 + minute;
}

std::string Time::get_formatted() const
{
    return (hour < 10 ? "0" : "") + std::to_string(hour) + ":" + (minute < 10 ? "0" : "") + std::to_string(minute);
}
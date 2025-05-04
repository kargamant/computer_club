#include <Time.hpp>

int Time::get_in_minutes()
{
    return hour*60 + minute;
}

std::string Time::get_formatted() const
{
    return (hour < 10 ? "0" : "") + std::to_string(hour) + ":" + (minute < 10 ? "0" : "") + std::to_string(minute);
}

std::ostream& operator<<(std::ostream& st, const Time& time)
{
    st << time.get_formatted();
    return st;
}

Time& Time::operator=(const Time& ntime)
{
    hour = ntime.hour;
    minute = ntime.minute;
    return *this;
}

Time operator-(Time& time1, Time& time2)
{
    int diff = time1.get_in_minutes() - time2.get_in_minutes();
    return {diff/60, diff%60};
}
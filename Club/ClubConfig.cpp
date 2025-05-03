#include <ClubConfig.hpp>
#include <iostream>

void operator<<(std::ostream& st, const ClubConfig& cf)
{
    st << "ClubConfig:" << std::endl;
    st << "n: " << cf.n << std::endl;
    st << "open_time: " << cf.open_time.get_formatted() << std::endl;
    st << "close_time: " << cf.close_time.get_formatted() << std::endl;
    st << "hour_price: " << cf.hour_price << std::endl;
}

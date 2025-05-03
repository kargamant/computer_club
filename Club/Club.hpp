#include <Time.hpp>
#include <queue>
#include <Table.hpp>
#include <unordered_map>
#include <ClubConfig.hpp>

class Club
{
    private:
        // config data
        int n;
        Time open_time;
        Time close_time;
        int hour_price;

        // processing data
        int occupied_tables;
        std::queue<std::string> wait_line;
        std::vector<Table> tables;
        std::unordered_map<std::string, int> client_map;
        int total_revenue;
    public:
        Club(int n, Time open_time, Time close_time, int hour_price);
};

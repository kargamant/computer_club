#pragma once
#include <Time.hpp>
#include <queue>
#include <Table.hpp>
#include <unordered_map>
#include <ClubConfig.hpp>
#include <string>

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
    public:
        Club(int n=0, Time open_time={-1,-1}, Time close_time={-1,-1}, int hour_price=0);
        Club(const ClubConfig& config);
        void setConfig(const ClubConfig& config);

        bool isInClub(const std::string& client);
        bool isInTime(Time& time);
        bool isFreeTables();
        bool isLineFull();
        bool isTableBusy(int table_number);

        int get_client_table(const std::string& client);
        void add_client(const std::string& client);
        void wait_client(const std::string& client);
        int remove_client(Time exit_time, const std::string& client);
        std::string get_client_from_line();
        void sit_client_table(Time enter_time, const std::string& client, int table_number);
        std::vector<std::string> flush_clients();

        friend class Outputter;
        friend class Pipeline;
};

#include <regex>
#include <fstream>
#include <Club.hpp>
#include <ClubConfig.hpp>
#include <EventConfig.hpp>

class Parser
{
    private:
        static std::string time_pattern;
        static std::string client_name_pattern;
        static std::string positive_number_pattern;

        static std::regex n_re;
        static std::regex open_close_time_re;
        static std::regex hour_price_re;
        static std::regex client_event_re;
        static std::regex table_event_re;

        static bool next_str(std::ifstream& fs, std::string& line, std::smatch& match, std::regex& re);
        static void throw_format_exception(const std::string& line);
    public:
        // creates club object with configuration in first 3 lines
        static ClubConfig parse_config(std::ifstream& fs);
        // parses excactly one event
        static EventConfig parse_event(std::ifstream& fs);
};

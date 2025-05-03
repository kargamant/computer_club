#include <regex>
#include <fstream>
#include <Club.hpp>
#include <ClubConfig.hpp>
#include <EventConfig.hpp>

class Parser
{
    private:
        std::regex n_re{"([1-9]|[1-9][0-9]+)"};
        std::regex time_re{"([0-1][0-9]|2[0-4]):([0-5][0-9])"};
        std::regex hour_price_re{"([1-9]|[1-9][0-9]+)"};
        std::regex client_name_re{"[a-z0-9_-]+"};

    public:

        // creates club object with configuration in first 3 lines
        ClubConfig parse_config(std::ifstream& fs);
        // parses excactly one event
        EventConfig parse_event(std::ifstream& fs);
};

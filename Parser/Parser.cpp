#include <Parser.hpp>
#include <iostream>
#include <exception>

std::string Parser::time_pattern{"(([0-1][0-9]|2[0-4]):([0-5][0-9]))"};
std::string Parser::client_name_pattern{"([a-z0-9_-]+)"};
std::string Parser::positive_number_pattern{"([1-9]|[1-9][0-9]+)"};

std::regex Parser::n_re{Parser::positive_number_pattern};
std::regex Parser::open_close_time_re{Parser::time_pattern + " " + Parser::time_pattern};
std::regex Parser::hour_price_re{Parser::positive_number_pattern};
std::regex Parser::client_event_re{Parser::time_pattern + " " + Parser::positive_number_pattern + " " + Parser::client_name_pattern};
std::regex Parser::table_event_re{Parser::time_pattern + " " + Parser::positive_number_pattern + " " + Parser::client_name_pattern + " " + Parser::positive_number_pattern};

bool Parser::next_str(std::ifstream& fs, std::string& line, std::smatch& match, std::regex& re)
{
    std::getline(fs, line);
    std::regex_match(line, match, re);
    return match.empty();
}

void Parser::throw_format_exception(const std::string& line)
{
    throw std::runtime_error("Error. Invalid format: \"" + line + "\"\n");
}

ClubConfig Parser::parse_config(std::ifstream& fs)
{
    ClubConfig cf;
    std::smatch match;
    std::string line;

    if(next_str(fs, line, match, n_re))
        throw_format_exception(line);
    else
        cf.n = stoi(match.str(1));
    
    if(next_str(fs, line, match, open_close_time_re))
        throw_format_exception(line);
    else
    {
        cf.open_time = {stoi(match.str(2)), stoi(match.str(3))};
        cf.close_time = {stoi(match.str(5)), stoi(match.str(6))};
    }

    if(next_str(fs, line, match, hour_price_re))
        throw_format_exception(line);
    else
        cf.hour_price = stoi(match.str(1));

    return cf;
}

EventConfig Parser::parse_event(std::ifstream& fs)
{
    std::smatch match;
    std::string line;

    std::getline(fs, line);

    if(std::regex_match(line, match, client_event_re))
        return (ClientEventConfig){{stoi(match.str(2)), stoi(match.str(3))}, (EventType)stoi(match.str(4)), match.str(5)};
    else if(std::regex_match(line, match, table_event_re))
        return (TableEventConfig){{stoi(match.str(2)), stoi(match.str(3))}, (EventType)stoi(match.str(4)), match.str(5), stoi(match.str(6))};
    else if(!line.empty())
        throw_format_exception(line);

    return (InfoEventConfig){{-1,-1}, EventType::end};
}

#include <Parser.hpp>
#include <iostream>
#include <exception>

std::regex Parser::n_re{"([1-9]|[1-9][0-9]+)"};
std::regex Parser::time_re{"([0-1][0-9]|2[0-4]):([0-5][0-9])"};
std::regex Parser::open_close_time_re{"(([0-1][0-9]|2[0-3]):([0-5][0-9])) (([0-1][0-9]|2[0-3]):([0-5][0-9]))"};
std::regex Parser::hour_price_re{"([1-9]|[1-9][0-9]+)"};
std::regex Parser::client_name_re{"[a-z0-9_-]+"};

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
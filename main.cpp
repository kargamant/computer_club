#include <Parser/Parser.hpp>
#include <iostream>
#include <fstream>
#include <exception>

int main(int argc, char* argv[])
{
    std::ifstream fs{argv[1]};

    try
    {
        ClubConfig cf = Parser::parse_config(fs);
        std::cout << cf;
        while(!fs.eof())
        {
            EventConfig ef = Parser::parse_event(fs);
        }

    }
    catch(std::runtime_error err)
    {
        std::cout << err.what() <<std::endl;
    }

    return 0;
}
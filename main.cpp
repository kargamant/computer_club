#include <Parser/Parser.hpp>
#include <iostream>
#include <fstream>
#include <exception>
#include <EventFactory.hpp>

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
            Event* event = EventFactory::create_event(ef).get();
        }

    }
    catch(std::runtime_error err)
    {
        std::cout << err.what() <<std::endl;
    }

    return 0;
}
#include <Parser/Parser.hpp>
#include <iostream>
#include <fstream>
#include <exception>
#include <EventFactory.hpp>
#include <EventHandler.hpp>

int main(int argc, char* argv[])
{
    std::ifstream fs{argv[1]};

    try
    {
        ClubConfig cf = Parser::parse_config(fs);
        std::cout << cf;
        Club club{cf};
        EventHandler handler{&club};

        while(!fs.eof())
        {
            EventConfig ef = Parser::parse_event(fs);
            std::unique_ptr<BaseEvent> event = EventFactory::create_event(ef);
            event->accept(handler);
        }

    }
    catch(std::runtime_error err)
    {
        std::cout << err.what() <<std::endl;
    }

    return 0;
}
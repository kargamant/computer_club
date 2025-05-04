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
            EventConfig input_ef = Parser::parse_event(fs);
            std::unique_ptr<BaseEvent> input_event = EventFactory::create_event(input_ef);

            EventConfig output_ef = input_event->accept(handler);
            std::unique_ptr<BaseEvent> output_event = EventFactory::create_event(output_ef);


        }

    }
    catch(std::runtime_error err)
    {
        std::cout << err.what() <<std::endl;
    }

    return 0;
}
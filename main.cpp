#include <Parser/Parser.hpp>
#include <iostream>
#include <fstream>
#include <exception>
#include <EventFactory.hpp>
#include <EventHandler.hpp>
#include <Outputter.hpp>

int main(int argc, char* argv[])
{
    std::ifstream fs{argv[1]};

    try
    {
        ClubConfig cf = Parser::parse_config(fs);
        
        Club club{cf};
        EventHandler handler{&club};
        Outputter outputter{&club};

        while(!fs.eof())
        {
            EventConfig input_ef = Parser::parse_event(fs);
            std::unique_ptr<BaseEvent> input_event = EventFactory::create_event(input_ef);

            outputter.print(std::cout, input_event.get());

            EventConfig output_ef = input_event->accept(handler);
            std::unique_ptr<BaseEvent> output_event = EventFactory::create_event(output_ef);
            
            if(output_event.get()->getType() != EventType::empty)
                outputter.print(std::cout, output_event.get());
        }

    }
    catch(std::runtime_error err)
    {
        std::cout << err.what() <<std::endl;
    }

    return 0;
}
#include <Pipeline.hpp>
#include <fstream>
#include <Parser.hpp>

void Pipeline::make_report(const std::string& filename, std::ostream& st)
{
    std::ifstream fs{filename};

    try
    {
        ClubConfig cf = Parser::parse_config(fs);
        
        club.setConfig(cf);
        handler.setClub(&club);
        outputter.setClub(&club);
        outputter.setStream(&st);

        outputter.print_open_time();
        while(!fs.eof())
        {
            EventConfig input_ef = Parser::parse_event(fs);
            std::unique_ptr<BaseEvent> input_event = EventFactory::create_event(input_ef);

            outputter.print_event(input_event.get());

            EventConfig output_ef = input_event->accept(handler);
            std::unique_ptr<BaseEvent> output_event = EventFactory::create_event(output_ef);
            
            if(output_event.get()->getType() != EventType::empty)
                outputter.print_event(output_event.get());
        }

        std::vector<std::string> remaining = club.flush_clients();
        for(auto& client: remaining)
        {
            ClientEventConfig cf{club.close_time, EventType::out_client_exit, client};
            std::unique_ptr<BaseEvent> exit_event = EventFactory::create_event(cf);
            outputter.print_event(exit_event.get());
        }

        outputter.print_close_time();
        outputter.print_all_tables();
    }
    catch(std::runtime_error err)
    {
        st << err.what() <<std::endl;
    }
}
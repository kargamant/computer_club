#include <Outputter.hpp>

void Outputter::print(std::ostream& st, BaseEvent* event)
{
    std::cout << event->get_formatted() << std::endl;
}
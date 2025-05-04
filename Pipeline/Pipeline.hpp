#include <Club.hpp>
#include <EventFactory.hpp>
#include <EventHandler.hpp>
#include <Outputter.hpp>
#include <ostream>

class Pipeline
{
    private:
        Club club;
        EventHandler handler;
        Outputter outputter;
    public:
        void make_report(const std::string& filename, std::ostream& st);
};
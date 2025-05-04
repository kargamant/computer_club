#include <BaseEvent.hpp>
#include <Club.hpp>

class Outputter
{
    private:
        Club* club;
        std::ostream* st;
    public:
        Outputter(Club* club=nullptr, std::ostream* st=nullptr) : club(club), st(st) {}
        void setClub(Club* club) {this->club = club;}
        void setStream(std::ostream* st) {this->st = st;}

        void print_event(BaseEvent* event);
        void print_open_time();
        void print_close_time();
        void print_table(int table_number);
        void print_all_tables();
};
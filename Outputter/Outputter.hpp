#include <BaseEvent.hpp>
#include <Club.hpp>

class Outputter
{
    private:
        Club* club;
    public:
        Outputter(Club* club) : club(club) {}

        static void print(std::ostream& st, BaseEvent* event);
};
#include <BaseEvent.hpp>
#include <ClientEvent.hpp>
#include <TableEvent.hpp>
#include <ErrorEvent.hpp>
#include <InfoEvent.hpp>
#include <Club.hpp>

class EventHandler
{
    private:
        Club* club;

        EventConfig on_client_enter(ClientEvent* event);
        EventConfig on_client_wait(ClientEvent* event);
        EventConfig on_client_exit(ClientEvent* event);
        EventConfig on_client_sit(TableEvent* event);
    public:
        EventHandler(Club* club=nullptr) : club(club) {}
        void setClub(Club* club) {this->club = club;}

        EventConfig handle(ClientEvent* event);
        EventConfig handle(TableEvent* event);
        EventConfig handle(ErrorEvent* event);
        EventConfig handle(InfoEvent* event);
};
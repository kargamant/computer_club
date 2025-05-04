#include <BaseEvent.hpp>
#include <ClientEvent.hpp>
#include <TableEvent.hpp>
#include <ErrorEvent.hpp>
#include <EndEvent.hpp>
#include <EmptyEvent.hpp>
#include <Club.hpp>

class EventHandler
{
    private:
        Club* club;

        EventConfig on_client_enter(ClientEvent* event);
        EventConfig on_client_wait(ClientEvent* event);
        EventConfig on_client_exit(ClientEvent* event);
    public:
        EventHandler(Club* club) : club(club) {}

        EventConfig handle(ClientEvent* event);
        EventConfig handle(TableEvent* event);
        EventConfig handle(ErrorEvent* event);
        EventConfig handle(EndEvent* event);
        EventConfig handle(EmptyEvent* event);
};
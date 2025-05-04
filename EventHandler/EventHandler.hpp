#include <BaseEvent.hpp>
#include <ClientEvent.hpp>
#include <TableEvent.hpp>
#include <ErrorEvent.hpp>
#include <EndEvent.hpp>
#include <Club.hpp>

class EventHandler
{
    private:
        Club* club;
    public:
        EventHandler(Club* club) : club(club) {}

        void handle(ClientEvent* event);
        void handle(TableEvent* event);
        void handle(ErrorEvent* event);
        void handle(EndEvent* event);
};
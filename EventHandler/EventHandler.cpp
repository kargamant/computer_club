#include <EventHandler.hpp>
#include <iostream>

EventConfig EventHandler::handle(ClientEvent* event)
{
    switch(event->id)
    {
        case 1:
            return on_client_enter(event);
        case 3:
            return on_client_wait(event);
        case 4:
            return on_client_exit(event);
        default:
            return (InfoEventConfig){event->time, EventType::empty};
    }

    return (InfoEventConfig){event->time, EventType::empty};
}

EventConfig EventHandler::handle(TableEvent* event)
{
    switch(event->id)
    {
        case 2:
            return on_client_sit(event);
        default:
            return (InfoEventConfig){event->time, EventType::empty};
    }

    return (InfoEventConfig){event->time, EventType::empty};
}

EventConfig EventHandler::handle(ErrorEvent* event)
{
    return (InfoEventConfig){event->time, EventType::empty};
}

EventConfig EventHandler::handle(InfoEvent* event)
{
    return (InfoEventConfig){event->time, EventType::empty};
}

EventConfig EventHandler::on_client_enter(ClientEvent* event)
{
    if(club->isInClub(event->client_name))
        return (ErrorEventConfig){event->time, EventType::error, "YouShallNotPass"};
    else if(!club->isInTime(event->time))
        return (ErrorEventConfig){event->time, EventType::error, "NotOpenYet"};
    else
    {
        club->add_client(event->client_name);
        return (InfoEventConfig){event->time, EventType::empty};
    }
}

EventConfig EventHandler::on_client_wait(ClientEvent* event)
{
    if(club->isFreeTables())
        return (ErrorEventConfig){event->time, EventType::error, "ICanWaitNoLonger!"};
    else if(club->isLineFull())
    {
        club->remove_client(event->time, event->client_name);
        return (ClientEventConfig){event->time, EventType::out_client_exit, event->client_name};
    }
    else
        club->wait_client(event->client_name);
    return (InfoEventConfig){event->time, EventType::empty};
}

EventConfig EventHandler::on_client_exit(ClientEvent* event)
{
    if(!club->isInClub(event->client_name))
        return (ErrorEventConfig){event->time, EventType::error, "ClientUnknown"};
    int table_number = club->remove_client(event->time, event->client_name);
    if(table_number!=-1)
    {
        std::string new_client = club->get_client_from_line();
        if(!new_client.empty())
        {
            club->sit_client_table(event->time, new_client, table_number);
            return (TableEventConfig){event->time, EventType::out_client_sit, new_client, table_number+1};
        }
    }
    return (InfoEventConfig){event->time, EventType::empty};
}

EventConfig EventHandler::on_client_sit(TableEvent* event)
{
    if(!club->isInClub(event->client_name))
        return (ErrorEventConfig){event->time, EventType::error, "ClientUnknown"};
    else
    {

        if(club->isTableBusy(event->table_number))
            return (ErrorEventConfig){event->time, EventType::error, "PlaceIsBusy"};

        club->sit_client_table(event->time, event->client_name, event->table_number - 1);
    }
    return (InfoEventConfig){event->time, EventType::empty};
}
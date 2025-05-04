#include <EventConfig.hpp>
#include <BaseEvent.hpp>
#include <memory>

class EventFactory
{
    private:
        struct creator_visitor
        {
            std::unique_ptr<BaseEvent> operator()(const ClientEventConfig& config);
            std::unique_ptr<BaseEvent> operator()(const TableEventConfig& config);
            std::unique_ptr<BaseEvent> operator()(const ErrorEventConfig& config);
            std::unique_ptr<BaseEvent> operator()(const EndEventConfig& config);
            std::unique_ptr<BaseEvent> operator()(const EmptyEventConfig& config);
        };
    public:
        static std::unique_ptr<BaseEvent> create_event(const EventConfig& config);
};
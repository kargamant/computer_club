#include <EventConfig.hpp>
#include <Event.hpp>
#include <memory>

class EventFactory
{
    private:
        // template<typename T>
        // static std::unique_ptr<Event> alloc_event(const EventConfig& config);
        const auto visitor = overloads
        {
            
        };
    public:
        static std::unique_ptr<Event> create_event(const EventConfig& config);
};
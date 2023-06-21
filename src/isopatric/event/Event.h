#ifndef ISOPATRIC_EVENT_EVENT_H
#define ISOPATRIC_EVENT_EVENT_H

#include <isopatric/core/Base.h>

#define EVENT_CLASS_TYPE(type)                                          \
    static EventType getStaticType() { return EventType::type; }        \
    EventType getEventType() const override { return EventType::type; } \
    const char *getEventName() const override { return #type; }

#define EVENT_CLASS_CATEGORIES(categories) \
    int getEventCategories() const override { return categories; }

namespace isopatric::event
{
    enum class EventType
    {
        None = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        KeyPressed,
        KeyReleased,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    enum EventCategory
    {
        EventCategoryNone = 0,
        EventCategoryWindow = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
    };

    class Event
    {
    public:
        bool handled = false;

        virtual ~Event() = default;

        virtual EventType getEventType() const = 0;
        virtual int getEventCategories() const = 0;
        virtual const char *getEventName() const = 0;
        virtual std::string toString() const { return getEventName(); }
    };

    class EventDispatcher
    {
    public:
        EventDispatcher(Event &event) : mEvent(event) {}

        template <typename T, typename F>
        bool dispatch(const F &callback)
        {
            if (mEvent.getEventType() == T::getStaticType())
            {
                mEvent.handled |= callback(static_cast<T &>(mEvent));
                return true;
            }
            else
            {
                return false;
            }
        }

    private:
        Event &mEvent;
    };

    class UnknownEvent : public Event
    {
    public:
        EVENT_CLASS_TYPE(None)
        EVENT_CLASS_CATEGORIES(EventCategoryNone)
    };

    // Formatter for logging
    inline std::ostream &operator<<(std::ostream &os, const Event &e)
    {
        return os << e.toString();
    }
}

#endif // ISOPATRIC_EVENT_EVENT_H

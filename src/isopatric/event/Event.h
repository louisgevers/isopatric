#ifndef ISOPATRIC_EVENT_EVENT_H
#define ISOPATRIC_EVENT_EVENT_H

#include <isopatric/core/Base.h>

#define EVENT_CLASS_TYPE(type)                                          \
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
        KeyTyped,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryWindow = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
    };

    class Event
    {
    public:
        bool handled = false;

        virtual EventType getEventType() const = 0;
        virtual int getEventCategories() const = 0;
        virtual const char *getEventName() const = 0;
        virtual std::string toString() const { return getEventName(); }
    };

    // Formatter for logging
    inline std::ostream &operator<<(std::ostream &os, const Event &e)
    {
        return os << e.toString();
    }
}

#endif // ISOPATRIC_EVENT_EVENT_H

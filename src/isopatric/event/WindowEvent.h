#ifndef ISOPATRIC_EVENT_WINDOWEVENT_H
#define ISOPATRIC_EVENT_WINDOWEVENT_H

#include "Event.h"
#include <sstream>

namespace isopatric::event
{
    class WindowCloseEvent : public Event
    {
    public:
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORIES(EventCategoryWindow)
    };

    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : mWidth(width), mHeight(height) {}

        unsigned int getWidth() const { return mWidth; }
        unsigned int getHeight() const { return mHeight; }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << mWidth << " x " << mHeight;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORIES(EventCategoryWindow)

    private:
        unsigned int mWidth;
        unsigned int mHeight;
    };

    class WindowFocusEvent : public Event
    {
    public:
        EVENT_CLASS_TYPE(WindowFocus)
        EVENT_CLASS_CATEGORIES(EventCategoryWindow)
    };

    class WindowLostFocusEvent : public Event
    {
    public:
        EVENT_CLASS_TYPE(WindowLostFocus)
        EVENT_CLASS_CATEGORIES(EventCategoryWindow)
    };
}

#endif // ISOPATRIC_EVENT_WINDOWEVENT_H

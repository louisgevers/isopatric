#ifndef ISOPATRIC_EVENT_MOUSEEVENT_H
#define ISOPATRIC_EVENT_MOUSEEVENT_H

#include "Event.h"
#include <sstream>

namespace isopatric::event
{
    class MouseButtonEvent : public Event
    {
    public:
        int getMouseButton() { return mMouseButton; }

        EVENT_CLASS_CATEGORIES(EventCategoryInput | EventCategoryMouse)
    protected:
        MouseButtonEvent(int mouseButton)
            : mMouseButton(mouseButton) {}

        int mMouseButton;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int mouseButton)
            : MouseButtonEvent(mouseButton) {}

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressed: " << mMouseButton;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int mouseButton)
            : MouseButtonEvent(mouseButton) {}

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleased: " << mMouseButton;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };

    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float x, float y)
            : mMouseX(x), mMouseY(y) {}

        float getMouseX() const { return mMouseX; }
        float getMouseY() const { return mMouseY; }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseMoved: " << mMouseX << ", " << mMouseY;
            return ss.str();
        }

        EVENT_CLASS_CATEGORIES(EventCategoryInput | EventCategoryMouse)
        EVENT_CLASS_TYPE(MouseMoved)

    private:
        float mMouseX;
        float mMouseY;
    };

    class MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float xOffset, float yOffset)
            : mXOffset(xOffset), mYOffset(yOffset) {}

        float getXOffset() const { return mXOffset; }
        float getYOffset() const { return mYOffset; }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolled: " << mXOffset << ", " << mYOffset;
            return ss.str();
        }

        EVENT_CLASS_CATEGORIES(EventCategoryInput | EventCategoryMouse)
        EVENT_CLASS_TYPE(MouseScrolled)

    private:
        float mXOffset;
        float mYOffset;
    };
}

#endif // ISOPATRIC_EVENT_MOUSEEVENT_H

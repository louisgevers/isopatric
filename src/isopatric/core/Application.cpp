#include "Application.h"
#include <isopatric/core/Log.h>
#include <isopatric/window/Window.h>
#include <isopatric/event/Event.h>

namespace isopatric::core
{
    Application::Application()
        : mRunning(true)
    {
        LOG_DEBUG("Creating application");
        isopatric::window::WindowProps props{"Isopatric", 640, 480};
        mWindow = isopatric::window::Window::create(props);
        mEventQueue = isopatric::event::EventQueue::create();
    }

    Application::~Application()
    {
        LOG_DEBUG("Application destroyed");
    }

    void Application::run()
    {
        while (mRunning)
        {
            // TODO: event loop in separate function once dispatch
            while (true)
            {
                auto event = mEventQueue->poll();
                BREAK_IF_NOT(event)
                LOG_DEBUG(*event);
                // TODO dispatch
                if (event->getEventType() == isopatric::event::EventType::WindowClose)
                {
                    mRunning = false;
                }
            }
        }
    }
}
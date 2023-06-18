#ifndef ISOPATRIC_CORE_APPLICATION_H
#define ISOPATRIC_CORE_APPLICATION_H

#include <isopatric/core/Base.h>
#include <isopatric/window/Window.h>
#include <isopatric/event/EventQueue.h>

namespace isopatric::core
{
    class Application
    {
    public:
        Application();
        ~Application();
        void run();

    private:
        bool mRunning;
        Scope<isopatric::window::Window> mWindow;
        Scope<isopatric::event::EventQueue> mEventQueue;
    };
}
#endif // ISOPATRIC_CORE_APPLICATION_H

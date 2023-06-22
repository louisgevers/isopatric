#ifndef ISOPATRIC_CORE_APPLICATION_H
#define ISOPATRIC_CORE_APPLICATION_H

#include <isopatric/core/Base.h>
#include <isopatric/core/LayerStack.h>
#include <isopatric/window/Window.h>
#include <isopatric/event/EventQueue.h>
#include <isopatric/event/WindowEvent.h>

namespace isopatric::core
{
    class Application
    {
    public:
        Application();
        ~Application();
        void run();
        void eventLoop();

        bool onWindowClose(isopatric::event::WindowCloseEvent &event);

    private:
        bool mRunning;
        isopatric::core::LayerStack mLayerStack;
        Scope<isopatric::window::Window> mWindow;
        Scope<isopatric::event::EventQueue> mEventQueue;
    };
}
#endif // ISOPATRIC_CORE_APPLICATION_H

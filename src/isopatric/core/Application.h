#ifndef ISOPATRIC_CORE_APPLICATION_H
#define ISOPATRIC_CORE_APPLICATION_H

#include <isopatric/core/Base.h>
#include <isopatric/window/Window.h>

namespace isopatric::core
{
    class Application
    {
    public:
        Application();
        ~Application();
        void run();

    private:
        Scope<isopatric::window::Window> mWindow;
    };
}
#endif // ISOPATRIC_CORE_APPLICATION_H

#include "Application.h"
#include <isopatric/core/Log.h>
#include <isopatric/event/WindowEvent.h>

namespace isopatric::core
{
    Application::Application()
    {
        LOG_DEBUG("Application created");
    }

    Application::~Application()
    {
        LOG_DEBUG("Application destroyed");
    }

    void Application::run()
    {
        LOG_DEBUG("Application running");
        isopatric::event::WindowResizeEvent e{1240, 1080};
        LOG_DEBUG(e);
    }
}
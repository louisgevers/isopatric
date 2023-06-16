#include "Application.h"
#include <isopatric/core/Log.h>
#include <isopatric/window/Window.h>

namespace isopatric::core
{
    Application::Application()
    {
        LOG_DEBUG("Creating application");
        isopatric::window::WindowProps props{"Isopatric", 640, 480};
        mWindow = isopatric::window::Window::create(props);
    }

    Application::~Application()
    {
        LOG_DEBUG("Application destroyed");
    }

    void Application::run()
    {
    }
}
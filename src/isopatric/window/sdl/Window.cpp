#include "Window.h"

#include <isopatric/core/Assert.h>
#include <isopatric/core/Log.h>
#include <isopatric/window/Window.h>

#include <SDL2/SDL.h>

// TODO SDL specific code in SDL subclass
namespace isopatric::window
{
    Scope<Window> Window::create(WindowProps &props)
    {
        return isopatric::createScope<SDLWindow>(props);
    }

    SDLWindow::SDLWindow(WindowProps &props)
    {
        int success = SDL_InitSubSystem(SDL_INIT_VIDEO);
        ASSERT(success == 0, "Could not initialize SDL: {}", SDL_GetError());

        mWindow = SDL_CreateWindow(props.title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, props.width, props.height, SDL_WINDOW_SHOWN);
        ASSERT(mWindow != nullptr, "Could not create SDL window: {}", SDL_GetError());
    }

    SDLWindow::~SDLWindow()
    {
        SDL_DestroyWindow(mWindow);
        mWindow = nullptr;
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
    }

}
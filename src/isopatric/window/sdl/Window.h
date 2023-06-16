#ifndef ISOPATRIC_WINDOW_SDL_WINDOW_H
#define ISOPATRIC_WINDOW_SDL_WINDOW_H

#include <isopatric/core/Base.h>
#include <isopatric/window/Window.h>

#include <SDL2/SDL.h>

namespace isopatric::window
{
    class SDLWindow : public isopatric::window::Window
    {
    public:
        SDLWindow(WindowProps &props);
        ~SDLWindow();

    private:
        SDL_Window *mWindow;
    };
}

#endif // ISOPATRIC_WINDOW_SDL_WINDOW_H

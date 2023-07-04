#include "Window.h"

#include <isopatric/render/RenderCommand.h>

#include <SDL2/SDL.h>

namespace isopatric::window {
    Scope <Window> Window::create(WindowProps &props) {
        return isopatric::createScope<SDLWindow>(props);
    }

    SDLWindow::SDLWindow(WindowProps &props) {
        mWidth = props.width;
        mHeight = props.height;

        int success = SDL_InitSubSystem(SDL_INIT_VIDEO);
        ASSERT(success == 0, "Could not initialize SDL: {}", SDL_GetError());

        auto flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
        mWindow = SDL_CreateWindow(props.title,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   props.width,
                                   props.height,
                                   flags);
        ASSERT(mWindow != nullptr, "Could not create SDL window: {}", SDL_GetError());

        // Create the rendering context
        mRenderContext = render::RenderContext::create(mWindow);
        render::RenderCommand::setViewPort(0, 0, mWidth, mHeight);
    }

    SDLWindow::~SDLWindow() {
        SDL_DestroyWindow(mWindow);
        mWindow = nullptr;
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
    }

    void SDLWindow::onUpdate() {
        mRenderContext->swapBuffers();
    }

    void SDLWindow::onEvent(event::Event &event) {
        event::EventDispatcher dispatch{event};
        dispatch.dispatch<event::WindowResizeEvent>(BIND_FN(onWindowResize));
    }

    bool SDLWindow::onWindowResize(event::WindowResizeEvent &event) {
        mWidth = event.getWidth();
        mHeight = event.getHeight();
        return false;
    }
}
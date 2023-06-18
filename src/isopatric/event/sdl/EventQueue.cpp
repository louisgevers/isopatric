#include "EventQueue.h"
#include <isopatric/core/Assert.h>
#include <isopatric/core/Base.h>
#include <isopatric/core/Log.h>
#include <isopatric/event/Event.h>
#include <isopatric/event/KeyEvent.h>
#include <isopatric/event/MouseEvent.h>
#include <isopatric/event/WindowEvent.h>

namespace isopatric::event
{
    Scope<EventQueue> EventQueue::create()
    {
        return createScope<SDLEventQueue>();
    }

    SDLEventQueue::SDLEventQueue()
    {
        int success = SDL_InitSubSystem(SDL_INIT_EVENTS);
        ASSERT(success == 0, "Failed to initialize SDL events: ", SDL_GetError());
    }

    Scope<Event> SDLEventQueue::poll()
    {
        Scope<Event> event;
        // Poll until matching event or no sdl events left
        while (SDL_PollEvent(&mEvent))
        {
            auto event = convertEvent(mEvent);
            if (event)
            {
                return event;
            }
        }
        return nullptr;
    }

    inline Scope<Event> const SDLEventQueue::convertEvent(SDL_Event &sdlEvent)
    {
        // TODO implement all our custom type events
        switch (sdlEvent.type)
        {
        case SDL_QUIT:
            return isopatric::createScope<WindowCloseEvent>();
        case SDL_WINDOWEVENT:
            switch (sdlEvent.window.event)
            {
            case SDL_WINDOWEVENT_SIZE_CHANGED:
                return isopatric::createScope<WindowResizeEvent>(sdlEvent.window.data1, sdlEvent.window.data2);
            }
        }

        return nullptr;
    }

    SDLEventQueue::~SDLEventQueue()
    {
        SDL_QuitSubSystem(SDL_INIT_EVENTS);
    }
}
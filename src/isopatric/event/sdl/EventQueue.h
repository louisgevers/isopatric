#ifndef ISOPATRIC_EVENT_SDL_EVENTQUEUE_H
#define ISOPATRIC_EVENT_SDL_EVENTQUEUE_H

#include <isopatric/core/Base.h>
#include <isopatric/event/EventQueue.h>
#include <isopatric/event/Event.h>

#include <SDL2/SDL.h>

namespace isopatric::event
{
    class SDLEventQueue : public EventQueue
    {
    public:
        SDLEventQueue();
        ~SDLEventQueue() override;

        Scope<Event> poll() override;

    private:
        SDL_Event mEvent;
        inline Scope<Event> const convertEvent(SDL_Event &sdlEvent);
    };
}

#endif // ISOPATRIC_EVENT_SDL_EVENTQUEUE_H

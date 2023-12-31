#include "EventQueue.h"
#include <isopatric/core/Assert.h>
#include <isopatric/core/Base.h>
#include <isopatric/core/Log.h>
#include <isopatric/event/Event.h>
#include <isopatric/event/KeyEvent.h>
#include <isopatric/event/MouseEvent.h>
#include <isopatric/event/WindowEvent.h>

#include <isopatric/input/sdl/Input.h>

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

	inline Scope<Event> const SDLEventQueue::convertEvent(SDL_Event& sdlEvent)
	{
		switch (sdlEvent.type)
		{
			// --- WINDOW EVENTS ---
		case SDL_QUIT:
			return isopatric::createScope<WindowCloseEvent>();
		case SDL_WINDOWEVENT:
			switch (sdlEvent.window.event)
			{
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				return isopatric::createScope<WindowResizeEvent>(sdlEvent.window.data1, sdlEvent.window.data2);
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				return isopatric::createScope<WindowFocusEvent>();
			case SDL_WINDOWEVENT_FOCUS_LOST:
				return isopatric::createScope<WindowLostFocusEvent>();
			}
			break;
			// --- KEY EVENTS ---
		case SDL_KEYDOWN:
		{
			input::KeyCode keyCode = input::keyCodeFromSDL(sdlEvent.key.keysym.sym);
			return isopatric::createScope<KeyPressedEvent>(keyCode, sdlEvent.key.repeat);
		}
		case SDL_KEYUP:
		{
			input::KeyCode keyCode = input::keyCodeFromSDL(sdlEvent.key.keysym.sym);
			return isopatric::createScope<KeyReleasedEvent>(keyCode);
		}
		case SDL_TEXTINPUT:
			return isopatric::createScope<KeyInputEvent>(sdlEvent.text.text);
			// --- MOUSE EVENTS ---
		case SDL_MOUSEMOTION:
			return isopatric::createScope<MouseMovedEvent>(sdlEvent.motion.x, sdlEvent.motion.y);
		case SDL_MOUSEBUTTONDOWN:
		{
			input::MouseCode mouseCode = input::mouseCodeFromSDL(sdlEvent.button.button);
			return isopatric::createScope<MouseButtonPressedEvent>(mouseCode,
				sdlEvent.button.x,
				sdlEvent.button.y);
		}
		case SDL_MOUSEBUTTONUP:
		{
			input::MouseCode mouseCode = input::mouseCodeFromSDL(sdlEvent.button.button);
			return isopatric::createScope<MouseButtonReleasedEvent>(mouseCode,
				sdlEvent.button.x,
				sdlEvent.button.y);
		}
		case SDL_MOUSEWHEEL:
			return isopatric::createScope<MouseScrolledEvent>(sdlEvent.wheel.x, sdlEvent.wheel.y);
		}

		return nullptr;
	}

	SDLEventQueue::~SDLEventQueue()
	{
		SDL_QuitSubSystem(SDL_INIT_EVENTS);
	}
}
#ifndef ISOPATRIC_WINDOW_SDL_WINDOW_H
#define ISOPATRIC_WINDOW_SDL_WINDOW_H

#include <isopatric/core/Base.h>
#include <isopatric/window/Window.h>
#include <isopatric/event/Event.h>
#include <isopatric/event/WindowEvent.h>

#include <SDL2/SDL.h>

namespace isopatric::window
{
	class SDLWindow : public Window
	{
	 public:
		explicit SDLWindow(WindowProps& props);
		~SDLWindow() override;

		void onUpdate() override;
		void onEvent(event::Event& event) override;

	 private:
		bool onWindowResize(event::WindowResizeEvent& event);
		SDL_Window* mWindow;
	};
}

#endif // ISOPATRIC_WINDOW_SDL_WINDOW_H

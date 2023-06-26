#include "Input.h"

#include <SDL.h>
#include <isopatric/input/Input.h>

namespace isopatric::input
{
	Scope<Input> Input::create()
	{
		return isopatric::createScope<SDLInput>();
	}

	SDLInput::~SDLInput() = default;

	bool SDLInput::isKeyPressed(int keyCode) const
	{
		auto keyboardState = SDL_GetKeyboardState(nullptr);
		// TODO: update when using custom keycodes
		return keyboardState[keyCode];
	}

	bool SDLInput::isMouseButtonPressed(int mouseButton) const
	{
		auto mouseState = SDL_GetMouseState(nullptr, nullptr);
		// TODO: update when using custom keycodes
		return mouseState & SDL_BUTTON(mouseButton);
	}

	int SDLInput::getMouseX() const
	{
		int x = 0;
		SDL_GetMouseState(&x, nullptr);
		return x;
	}

	int SDLInput::getMouseY() const
	{
		int y = 0;
		SDL_GetMouseState(nullptr, &y);
		return y;
	}

	std::pair<int, int> SDLInput::getMousePosition() const
	{
		int x, y = 0;
		SDL_GetMouseState(&x, &y);
		return std::make_pair(x, y);
	}
}

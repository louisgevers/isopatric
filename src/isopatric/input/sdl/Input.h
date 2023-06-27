#ifndef ISOPATRIC_SDL_INPUT_H
#define ISOPATRIC_SDL_INPUT_H

#include <isopatric/input/Input.h>
#include <isopatric/input/KeyCode.h>
#include <isopatric/input/MouseCode.h>

namespace isopatric::input
{

	class SDLInput : public Input
	{
	 public:
		~SDLInput() override;
		bool isKeyPressed(KeyCode keyCode) const override;
		bool isMouseButtonPressed(MouseCode mouseButton) const override;
		int getMouseX() const override;
		int getMouseY() const override;
		std::pair<int, int> getMousePosition() const override;
	};

	KeyCode keyCodeFromSDL(int keyCode);
	int keyCodeToSDL(KeyCode keyCode);
	MouseCode mouseCodeFromSDL(int mouseCode);
	int mouseCodeToSDL(MouseCode mouseCode);
}

#endif //ISOPATRIC_SDL_INPUT_H

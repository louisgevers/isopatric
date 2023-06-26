#ifndef ISOPATRIC_SDL_INPUT_H
#define ISOPATRIC_SDL_INPUT_H

#include <isopatric/input/Input.h>

namespace isopatric::input
{

	class SDLInput : public Input
	{
	 public:
		~SDLInput() override;
		bool isKeyPressed(int keyCode) const override;
		bool isMouseButtonPressed(int mouseButton) const override;
		int getMouseX() const override;
		int getMouseY() const override;
		std::pair<int, int> getMousePosition() const override;
	};
}

#endif //ISOPATRIC_SDL_INPUT_H

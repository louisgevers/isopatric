#ifndef ISOPATRIC_INPUT_H
#define ISOPATRIC_INPUT_H

#include "KeyCode.h"
#include "MouseCode.h"

namespace isopatric::input
{

	class Input
	{
	 public:
		virtual ~Input() = default;

		static Scope<Input> create();

		virtual bool isKeyPressed(KeyCode keyCode) const = 0;

		virtual bool isMouseButtonPressed(MouseCode mouseButton) const = 0;

		virtual int getMouseX() const = 0;

		virtual int getMouseY() const = 0;

		virtual std::pair<int, int> getMousePosition() const = 0;
	};

}

#endif //ISOPATRIC_INPUT_H

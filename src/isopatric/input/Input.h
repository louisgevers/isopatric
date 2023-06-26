#ifndef ISOPATRIC_INPUT_H
#define ISOPATRIC_INPUT_H

namespace isopatric::input
{

	class Input
	{
	 public:
		virtual ~Input() = default;

		static Scope<Input> create();

		virtual bool isKeyPressed(int keyCode) const = 0;

		virtual bool isMouseButtonPressed(int mouseButton) const = 0;

		virtual int getMouseX() const = 0;

		virtual int getMouseY() const = 0;

		virtual std::pair<int, int> getMousePosition() const = 0;
	};

}

#endif //ISOPATRIC_INPUT_H

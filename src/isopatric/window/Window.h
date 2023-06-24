#ifndef ISOPATRIC_WINDOW_WINDOW_H
#define ISOPATRIC_WINDOW_WINDOW_H

#include <isopatric/core/Base.h>
#include <isopatric/event/Event.h>

namespace isopatric::window
{
	struct WindowProps
	{
		const char* title;
		const unsigned int width;
		const unsigned int height;
	};

	class Window
	{
	 public:
		virtual ~Window() = default;

		static Scope<Window> create(WindowProps& props);

		virtual void onUpdate() = 0;
		virtual void onEvent(event::Event& event) = 0;

		inline unsigned int getWidth() const { return mWidth; }
		inline unsigned int getHeight() const { return mHeight; }

	 protected:
		unsigned int mWidth;
		unsigned int mHeight;
	};
}

#endif // ISOPATRIC_WINDOW_WINDOW_H

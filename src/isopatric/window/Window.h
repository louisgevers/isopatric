#ifndef ISOPATRIC_WINDOW_WINDOW_H
#define ISOPATRIC_WINDOW_WINDOW_H

#include <isopatric/core/Base.h>
#include <isopatric/event/Event.h>
#include <isopatric/render/RenderContext.h>

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

		render::RenderContext& getRenderContext() const { return *mRenderContext; }

	 protected:
		unsigned int mWidth;
		unsigned int mHeight;
		Scope<render::RenderContext> mRenderContext;
	};
}

#endif // ISOPATRIC_WINDOW_WINDOW_H

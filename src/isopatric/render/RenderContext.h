#ifndef ISOPATRIC_SRC_ISOPATRIC_RENDER_RENDERCONTEXT_H
#define ISOPATRIC_SRC_ISOPATRIC_RENDER_RENDERCONTEXT_H

namespace isopatric::render
{
	class RenderContext
	{
	 public:
		virtual ~RenderContext() = default;
		virtual void swapBuffers() = 0;

		static Scope<RenderContext> create(void* window); // Render context is window implementation specific
	};
}

#endif //ISOPATRIC_SRC_ISOPATRIC_RENDER_RENDERCONTEXT_H

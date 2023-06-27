#ifndef ISOPATRIC_SRC_ISOPATRIC_RENDER_OPENGL_RENDERCONTEXT_H
#define ISOPATRIC_SRC_ISOPATRIC_RENDER_OPENGL_RENDERCONTEXT_H

#include <isopatric/render/RenderContext.h>

#include "SDL.h"

namespace isopatric::render
{
	class GLRenderContext : public RenderContext
	{
	 public:
		explicit GLRenderContext(SDL_Window* window);
		~GLRenderContext() override;
		void swapBuffers() override;

		SDL_GLContext& getGLContext() { return mContext; }
	 private:
		SDL_Window* mWindow;
		SDL_GLContext mContext;
	};
}

#endif //ISOPATRIC_SRC_ISOPATRIC_RENDER_OPENGL_RENDERCONTEXT_H

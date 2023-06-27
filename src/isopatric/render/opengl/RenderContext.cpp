#include "RenderContext.h"

#include <glad/glad.h>

namespace isopatric::render
{
	Scope<RenderContext> RenderContext::create(void* window)
	{
		return createScope<GLRenderContext>(static_cast<SDL_Window*>(window));
	}

	GLRenderContext::GLRenderContext(SDL_Window* window)
		: mWindow(window)
	{
		// Needed for higher versions of OpenGL on MacOS
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		mContext = SDL_GL_CreateContext(window);
		ASSERT(mContext != nullptr, "Could not create SDL GL context: {}", SDL_GetError());
		SDL_GL_MakeCurrent(mWindow, mContext);

		// Enable vsync
		SDL_GL_SetSwapInterval(1);
		int success = gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
		ASSERT(success, "Could not initialize GLAD: {}", glad_glGetError());
		LOG_INFO("OpenGL initialized: version {}.{}", GLVersion.major, GLVersion.minor);
	}

	GLRenderContext::~GLRenderContext()
	{
		SDL_GL_DeleteContext(mContext);
	}

	void GLRenderContext::swapBuffers()
	{
		SDL_GL_SwapWindow(mWindow);
	}
}

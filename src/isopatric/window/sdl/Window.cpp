#include "Window.h"

#include <isopatric/core/Assert.h>
#include <isopatric/core/Log.h>
#include <isopatric/window/Window.h>

#include <SDL2/SDL.h>
#include <glad/glad.h>

namespace isopatric::window
{
	Scope<Window> Window::create(WindowProps& props)
	{
		return isopatric::createScope<SDLWindow>(props);
	}

	SDLWindow::SDLWindow(WindowProps& props)
	{
		int success = SDL_InitSubSystem(SDL_INIT_VIDEO);
		ASSERT(success == 0, "Could not initialize SDL: {}", SDL_GetError());

		auto flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
		mWindow = SDL_CreateWindow(props.title,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			props.width,
			props.height,
			flags);
		ASSERT(mWindow != nullptr, "Could not create SDL window: {}", SDL_GetError());

		mGLContext = SDL_GL_CreateContext(mWindow);
		ASSERT(mGLContext != nullptr, "Could not create SDL GL context: {}", SDL_GetError());
		SDL_GL_MakeCurrent(mWindow, mGLContext);

		// Enable vsync
		SDL_GL_SetSwapInterval(1);
		success = gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
		ASSERT(success, "Could not initialize GLAD: {}", glad_glGetError());
		LOG_INFO("OpenGL initialized: version {}.{}", GLVersion.major, GLVersion.minor);

		glViewport(0, 0, props.width, props.height);
	}

	SDLWindow::~SDLWindow()
	{
		SDL_GL_DeleteContext(mGLContext);
		SDL_DestroyWindow(mWindow);
		mWindow = nullptr;
		mGLContext = nullptr;
		SDL_QuitSubSystem(SDL_INIT_VIDEO);
	}

}
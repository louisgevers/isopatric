#include "Application.h"
#include <isopatric/core/Base.h>
#include <isopatric/window/Window.h>
#include <isopatric/event/Event.h>

// TODO temporary
#include <glad/glad.h>

namespace isopatric::core
{
	Application* Application::sInstance = nullptr;

	Application::Application()
		: mRunning(true), mLayerStack()
	{
		ASSERT(!sInstance, "Application already exists!");
		sInstance = this;

		LOG_DEBUG("Creating application instance");
		window::WindowProps props{ "Isopatric", 640, 480 };
		mWindow = window::Window::create(props);
		mEventQueue = event::EventQueue::create();
	}

	Application::~Application()
	{
		LOG_DEBUG("Application destroyed");
		sInstance = nullptr;
	}

	void Application::run()
	{
		while (mRunning)
		{
			// TODO shouldn't be here
			glClearColor(0, 1, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			eventLoop();
			for (Layer* layer : mLayerStack)
			{
				layer->onUpdate();
			}
			mWindow->onUpdate();
		}
	}

	void Application::eventLoop()
	{
		while (true)
		{
			auto event = mEventQueue->poll();
			if (event)
			{
				// Application events
				event::EventDispatcher dispatch{ *event };
				dispatch.dispatch<event::WindowCloseEvent>(BIND_FN(onWindowClose));
				// Layer events
				for (auto it = mLayerStack.rbegin(); it != mLayerStack.rend(); it++)
				{
					if (event->handled) { break; }
					(*it)->onEvent(*event);
				}
				// Window events
				mWindow->onEvent(*event);
			}
			else
			{
				return;
			}
		}
	}

	bool Application::onWindowClose(isopatric::event::WindowCloseEvent& event)
	{
		mRunning = false;
		return true;
	}
	void Application::pushLayer(Layer* layer)
	{
		mLayerStack.pushLayer(layer);
	}
	void Application::pushOverlay(Layer* layer)
	{
		mLayerStack.pushOverlay(layer);
	}
}
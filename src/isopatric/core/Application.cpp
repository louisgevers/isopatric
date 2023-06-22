#include "Application.h"
#include <isopatric/core/Log.h>
#include <isopatric/window/Window.h>
#include <isopatric/event/Event.h>

namespace isopatric::core
{
	Application::Application()
		: mRunning(true), mLayerStack()
	{
		LOG_DEBUG("Creating application");
		isopatric::window::WindowProps props{ "Isopatric", 640, 480 };
		mWindow = isopatric::window::Window::create(props);
		mEventQueue = isopatric::event::EventQueue::create();
	}

	Application::~Application()
	{
		LOG_DEBUG("Application destroyed");
	}

	void Application::run()
	{
		while (mRunning)
		{
			eventLoop();
			for (Layer* layer : mLayerStack)
			{
				layer->onUpdate();
			}
		}
	}

	void Application::eventLoop()
	{
		while (true)
		{
			auto event = mEventQueue->poll();
			if (event)
			{
				LOG_DEBUG(*event);
				// Application events
				isopatric::event::EventDispatcher dispatch{ *event };
				dispatch.dispatch<isopatric::event::WindowCloseEvent>(BIND_FN(onWindowClose));
				// Layer events
				for (auto it = mLayerStack.rbegin(); it != mLayerStack.rend(); it++)
				{
					if (event->handled) { break; }
					(*it)->onEvent(*event);
				}
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
}
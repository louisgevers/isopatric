#ifndef ISOPATRIC_CORE_APPLICATION_H
#define ISOPATRIC_CORE_APPLICATION_H

#include <isopatric/core/Base.h>
#include <isopatric/core/LayerStack.h>
#include <isopatric/window/Window.h>
#include <isopatric/event/EventQueue.h>
#include <isopatric/event/WindowEvent.h>

namespace isopatric::core
{
	class Application
	{
	 public:
		Application();
		~Application();
		void run();
		void eventLoop();

		bool onWindowClose(event::WindowCloseEvent& event);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* layer);

		inline window::Window& getWindow() { return *mWindow; }

		inline static Application& get() { return *sInstance; }
	 private:
		bool mRunning;
		core::LayerStack mLayerStack;
		Scope<window::Window> mWindow;
		Scope<event::EventQueue> mEventQueue;

		static Application* sInstance;
	};

	// Client hook
	Application* createApplication();
}
#endif // ISOPATRIC_CORE_APPLICATION_H

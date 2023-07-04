#include "Application.h"
#include <isopatric/core/Base.h>
#include <isopatric/window/Window.h>
#include <isopatric/event/Event.h>

namespace isopatric::core {
    Application *Application::sInstance = nullptr;

    Application::Application()
            : mRunning(true), mLayerStack() {
        ASSERT(!sInstance, "Application already exists!");
        sInstance = this;

        LOG_DEBUG("Creating application instance");
        window::WindowProps props{"Isopatric", 640, 480};
        mWindow = window::Window::create(props);
        mEventQueue = event::EventQueue::create();

        mUILayer = new ui::UILayer();
        mLayerStack.pushOverlay(mUILayer);
    }

    Application::~Application() {
        LOG_DEBUG("Application destroyed");
        sInstance = nullptr;
    }

    void Application::run() {
        while (mRunning) {
            eventLoop();
            for (Layer *layer: mLayerStack) {
                layer->onUpdate();
            }

            // This should probably be DEBUG only
            mUILayer->begin();
            for (Layer *layer: mLayerStack) {
                layer->onUIRender();
            }
            mUILayer->end();

            mWindow->onUpdate();
        }
    }

    void Application::eventLoop() {
        while (true) {
            auto event = mEventQueue->poll();
            if (event) {
                // Application events
                event::EventDispatcher dispatch{*event};
                dispatch.dispatch<event::WindowCloseEvent>(BIND_FN(onWindowClose));
                // Layer events
                for (auto it = mLayerStack.rbegin(); it != mLayerStack.rend(); it++) {
                    if (event->handled) { break; }
                    (*it)->onEvent(*event);
                }
                // Window events
                mWindow->onEvent(*event);
            } else {
                return;
            }
        }
    }

    bool Application::onWindowClose(isopatric::event::WindowCloseEvent &event) {
        mRunning = false;
        return true;
    }

    void Application::pushLayer(Layer *layer) {
        mLayerStack.pushLayer(layer);
    }

    void Application::pushOverlay(Layer *layer) {
        mLayerStack.pushOverlay(layer);
    }
}
//
// Created by Louis Gevers on 14/06/2023.
//
#include "Window.h"
#include <isopatric/core/Log.h>

namespace isopatric::window {
    Window::Window() {
        LOG_DEBUG("Hello window");
    }

    Window::~Window() {
        LOG_DEBUG("Goodbye window.");
    }
}
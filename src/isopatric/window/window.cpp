//
// Created by Louis Gevers on 14/06/2023.
//
#include <cstdio>
#include "window.h"

namespace isopatric::window {
    Window::Window() {
        printf("Hello window.\n");
    }

    Window::~Window() {
        printf("Goodbye window.\n");
    }
}
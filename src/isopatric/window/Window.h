#ifndef ISOPATRIC_WINDOW_WINDOW_H
#define ISOPATRIC_WINDOW_WINDOW_H

#include <isopatric/core/Base.h>

namespace isopatric::window
{
    struct WindowProps
    {
        const char *title;
        const unsigned int width;
        const unsigned int height;
    };

    class Window
    {
    public:
        virtual ~Window() = default;

        static Scope<Window> create(WindowProps &props);
    };
}

#endif // ISOPATRIC_WINDOW_WINDOW_H

#ifndef ISOPATRIC_CORE_LAYER_H
#define ISOPATRIC_CORE_LAYER_H

#include <isopatric/event/Event.h>

namespace isopatric::core {
    class Layer {
    public:
        virtual ~Layer() = default;

        virtual void onAttach() {}

        virtual void onDetach() {}

        virtual void onUpdate() {}

        virtual void onEvent(isopatric::event::Event &event) {}

        virtual void onUIRender() {};
    };
}

#endif // ISOPATRIC_CORE_LAYER_H

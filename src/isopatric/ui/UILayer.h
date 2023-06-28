#ifndef ISOPATRIC_ISOPATRIC_UI_UILAYER_H
#define ISOPATRIC_ISOPATRIC_UI_UILAYER_H

#include <isopatric/core/Layer.h>
#include <isopatric/event/KeyEvent.h>
#include <isopatric/event/MouseEvent.h>
#include <isopatric/event/WindowEvent.h>

namespace isopatric::ui {
    class UILayer : public core::Layer {
    public:
        void onAttach() override;

        void onDetach() override;

        void onEvent(event::Event &event) override;

        void begin();

        void end();

    private:
        bool onWindowResizeEvent(event::WindowResizeEvent &event);

        bool onKeyPressed(event::KeyPressedEvent &event);

        bool onKeyReleased(event::KeyReleasedEvent &event);

        bool onKeyInput(event::KeyInputEvent &event);

        bool onMouseButtonPressed(event::MouseButtonPressedEvent &event);

        bool onMouseButtonReleased(event::MouseButtonReleasedEvent &event);

        bool onMouseMoved(event::MouseMovedEvent &event);

        bool onMouseScrolled(event::MouseScrolledEvent &event);

        float mTime = 0.0f;
    };
}

#endif //ISOPATRIC_ISOPATRIC_UI_UILAYER_H

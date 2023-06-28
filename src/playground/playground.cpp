#include <isopatric/isopatric.h>

#include <imgui.h>

class TestLayer : public isopatric::core::Layer {
public:
    void onUIRender() override {
        ImGui::Begin("Test");
        ImGui::Text("Hello");
        ImGui::Button("Click me");
        ImGui::End();
    };
};

class PlayGround : public isopatric::core::Application {
public:
    PlayGround() {
        pushOverlay(new TestLayer());
    }
};

isopatric::core::Application *isopatric::core::createApplication() {
    return new PlayGround();
}
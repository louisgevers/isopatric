#include "UILayer.h"

#include <isopatric/core/Application.h>

#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>

namespace isopatric::ui {
    void UILayer::onAttach() {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO &io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ImGui_ImplOpenGL3_Init("#version 150");
        LOG_DEBUG("ImGui Initialized");

        auto &window = core::Application::get().getWindow();
        io.DisplaySize = ImVec2((float) window.getWidth(), (float) window.getHeight());
    }

    void UILayer::onDetach() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui::DestroyContext();
    }

    void UILayer::begin() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();
    }

    void UILayer::end() {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void UILayer::onEvent(event::Event &event) {
        event::EventDispatcher dispatch{event};
        dispatch.dispatch<event::WindowResizeEvent>(BIND_FN(onWindowResizeEvent));
        dispatch.dispatch<event::KeyPressedEvent>(BIND_FN(onKeyPressed));
        dispatch.dispatch<event::KeyReleasedEvent>(BIND_FN(onKeyReleased));
        dispatch.dispatch<event::KeyInputEvent>(BIND_FN(onKeyInput));
        dispatch.dispatch<event::MouseButtonPressedEvent>(BIND_FN(onMouseButtonPressed));
        dispatch.dispatch<event::MouseButtonReleasedEvent>(BIND_FN(onMouseButtonReleased));
        dispatch.dispatch<event::MouseMovedEvent>(BIND_FN(onMouseMoved));
        dispatch.dispatch<event::MouseScrolledEvent>(BIND_FN(onMouseScrolled));
    }

    bool UILayer::onWindowResizeEvent(event::WindowResizeEvent &event) {
        ImGuiIO &io = ImGui::GetIO();
        io.DisplaySize = ImVec2((float) event.getWidth(), (float) event.getHeight());
        return false;
    }

    bool UILayer::onKeyPressed(event::KeyPressedEvent &event) {
        ImGuiIO &io = ImGui::GetIO();
        io.AddKeyEvent(static_cast<ImGuiKey>(event.getKeyCode()), true);
        return false;
    }

    bool UILayer::onKeyReleased(event::KeyReleasedEvent &event) {
        ImGuiIO &io = ImGui::GetIO();
        io.AddKeyEvent(static_cast<ImGuiKey>(event.getKeyCode()), false);
        return false;
    }

    bool UILayer::onKeyInput(event::KeyInputEvent &event) {
        ImGuiIO &io = ImGui::GetIO();
        io.AddInputCharactersUTF8(event.getInput());
        return false;
    }

    bool UILayer::onMouseButtonPressed(event::MouseButtonPressedEvent &event) {
        ImGuiIO &io = ImGui::GetIO();
        io.MouseDown[event.getMouseButton()] = true;
        return false;
    }

    bool UILayer::onMouseButtonReleased(event::MouseButtonReleasedEvent &event) {
        ImGuiIO &io = ImGui::GetIO();
        io.MouseDown[event.getMouseButton()] = false;
        return false;
    }

    bool UILayer::onMouseMoved(event::MouseMovedEvent &event) {
        ImGuiIO &io = ImGui::GetIO();
        io.MousePos = ImVec2(event.getMouseX(), event.getMouseY());
        return false;
    }

    bool UILayer::onMouseScrolled(event::MouseScrolledEvent &event) {
        ImGuiIO &io = ImGui::GetIO();
        io.MouseWheelH += event.getXOffset();
        io.MouseWheel += event.getYOffset();
        return false;
    }
}
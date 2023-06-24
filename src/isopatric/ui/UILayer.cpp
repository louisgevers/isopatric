#include "UILayer.h"

#include <isopatric/core/Application.h>

#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>

// TODO: temporary
#include <SDL.h>

namespace isopatric::ui
{
	void UILayer::onAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		// TODO keymaps
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init("#version 150");
		LOG_INFO("ImGui Initialized");
	}

	void UILayer::onDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui::DestroyContext();
	}

	void UILayer::onUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		auto& app = core::Application::get();
		auto& window = app.getWindow();
		io.DisplaySize = ImVec2((float)window.getWidth(), (float)window.getHeight());

		// TODO: universal delta time handling
		float time = (float)SDL_GetTicks() / 1000.0f;
		io.DeltaTime = mTime > 0.0f && time - mTime > 0.0f ? (time - mTime) : (1.0f / 60.0f);
		mTime = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void UILayer::onEvent(event::Event& event) {}
}
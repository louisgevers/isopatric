#include <isopatric/core/Log.h>
#include <isopatric/core/Application.h>
#include <isopatric/render/RenderCommand.h>

int main() {
    isopatric::core::Log::init();

    auto application = isopatric::core::createApplication();

    // Initializations after the app is created
    isopatric::render::RenderCommand::init();

    application->run();
    delete application;
}
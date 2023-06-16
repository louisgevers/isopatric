#include <isopatric/core/Log.h>
#include <isopatric/core/Application.h>

int main()
{
    isopatric::core::Log::init();

    auto application = new isopatric::core::Application();
    application->run();
    delete application;
}
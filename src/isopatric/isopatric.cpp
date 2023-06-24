#include <isopatric/core/Log.h>
#include <isopatric/core/Application.h>

int main()
{
	isopatric::core::Log::init();

	auto application = isopatric::core::createApplication();
	application->run();
	delete application;
}
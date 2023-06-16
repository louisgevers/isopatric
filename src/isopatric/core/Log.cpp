#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace isopatric::core
{

    std::shared_ptr<spdlog::logger> Log::mLogger;

    void Log::init()
    {
        Log::mLogger = spdlog::stdout_color_mt("isopatric");
        Log::mLogger->set_level(spdlog::level::debug);
    }
}
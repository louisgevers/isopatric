#ifndef ISOPATRIC_CORE_LOG_H
#define ISOPATRIC_CORE_LOG_H

#include <spdlog/spdlog.h>

namespace isopatric::core
{
    class Log
    {
    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger> &getLogger()
        {
            return mLogger;
        }

    private:
        static std::shared_ptr<spdlog::logger> mLogger;
    };
}

#define LOG_DEBUG(...) isopatric::core::Log::getLogger()->debug(__VA_ARGS__)
#define LOG_INFO(...) isopatric::core::Log::getLogger()->info(__VA_ARGS__)
#define LOG_WARN(...) isopatric::core::Log::getLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) isopatric::core::Log::getLogger()->error(__VA_ARGS__)

#endif // ISOPATRIC_CORE_LOG_H

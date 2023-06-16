#ifndef ISOPATRIC_CORE_ASSERT_H
#define ISOPATRIC_CORE_ASSERT_H

#include "Log.h"

#include <signal.h>

#define ASSERT(assertion, msg, ...)  \
    if (!(assertion))                \
    {                                \
        LOG_ERROR(msg, __VA_ARGS__); \
        raise(SIGTRAP);              \
    }

#endif // ISOPATRIC_CORE_ASSERT_H

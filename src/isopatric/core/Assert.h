#ifndef ISOPATRIC_CORE_ASSERT_H
#define ISOPATRIC_CORE_ASSERT_H

#include "Base.h"

#include <signal.h>

#define INTERNAL_ISOPATRIC_ASSERT_NO_ARGS(assertion, msg) \
    if (!(assertion))                \
    {                                \
        LOG_ERROR(msg); \
        raise(SIGTRAP);              \
    }
#define INTERNAL_ISOPATRIC_ASSERT_ARGS(assertion, msg, ...)  \
    if (!(assertion))                \
    {                                \
        LOG_ERROR(msg, __VA_ARGS__); \
        raise(SIGTRAP);              \
    }

#define INTERNAL_ISOPATRIC_ASSERT_MACRO_NAME(arg1, arg2, arg3, macro, ...) macro
#define INTERNAL_ISOPATRIC_ASSERT_GET_MACRO(...) INTERNAL_ISOPATRIC_ASSERT_MACRO_NAME(__VA_ARGS__, INTERNAL_ISOPATRIC_ASSERT_ARGS, INTERNAL_ISOPATRIC_ASSERT_NO_ARGS)

#define ASSERT(...) INTERNAL_ISOPATRIC_ASSERT_GET_MACRO(__VA_ARGS__)(__VA_ARGS__)

#endif // ISOPATRIC_CORE_ASSERT_H

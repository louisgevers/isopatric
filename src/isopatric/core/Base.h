#ifndef ISOPATRIC_CORE_BASE_H
#define ISOPATRIC_CORE_BASE_H

#define BIT(x) (1 << x)
#define BREAK_IF_NOT(x) \
    {                   \
        if (!x)         \
        {               \
            break;      \
        }               \
    }
#define BIND_FN(fn) [this](auto &&...args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

#define EXPAND_MACRO(x) x

namespace isopatric {

    template<typename T>
    using Scope = std::unique_ptr<T>;

    template<typename T, typename... Args>
    constexpr Scope<T> createScope(Args &&...args) {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;

    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args &&... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

}

#include <isopatric/core/Assert.h>
#include <isopatric/core/Log.h>

#endif // ISOPATRIC_CORE_BASE_H

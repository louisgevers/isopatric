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

namespace isopatric
{

    template <typename T>
    using Scope = std::unique_ptr<T>;

    template <typename T, typename... Args>
    constexpr Scope<T> createScope(Args &&...args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

}

#endif // ISOPATRIC_CORE_BASE_H

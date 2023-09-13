#include "Math.h"

namespace isopatric::math {
    float radians(float degrees) {
        return degrees / 180 * PI;
    }

    float degrees(float radians) {
        return radians / PI * 180;
    }

    float clip(float value, float lb, float ub) {
        return std::clamp(value, lb, ub);
    }
}

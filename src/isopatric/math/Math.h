#ifndef ISOPATRIC_ISOPATRIC_MATH_MATH_H
#define ISOPATRIC_ISOPATRIC_MATH_MATH_H

namespace isopatric::math {

    const float PI = 3.14159265358979323846;

    float radians(float degrees);
    float degrees(float radians);

    float clip(float value, float lb, float ub);
}

#endif //ISOPATRIC_ISOPATRIC_MATH_MATH_H

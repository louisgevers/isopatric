#ifndef ISOPATRIC_ISOPATRIC_MATH_VECTOR_H
#define ISOPATRIC_ISOPATRIC_MATH_VECTOR_H

namespace isopatric::math {
    struct Vector3 {
        float x, y, z;

        Vector3 normalize() const;
        float length() const;

        Vector3 rotate(Vector3 &euler) const;

        Vector3 operator+(float scalar) const;
        Vector3 operator-(float scalar) const;
        Vector3 operator*(float scalar) const;
        Vector3 operator/(float scalar) const;

        Vector3 operator+(const Vector3 &other) const;
        Vector3 operator-(const Vector3 &other) const;

        Vector3 &operator+=(const Vector3 &other);
        Vector3 &operator-=(const Vector3 &other);

    };

    Vector3 operator+(float scalar, const Vector3 &v);
    Vector3 operator-(float scalar, const Vector3 &v);
    Vector3 operator*(float scalar, const Vector3 &v);
    Vector3 operator/(float scalar, const Vector3 &v);
}

#endif //ISOPATRIC_ISOPATRIC_MATH_VECTOR_H

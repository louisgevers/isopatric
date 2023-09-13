#include "Vector.h"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace isopatric::math {

    Vector3 Vector3::normalize() const {
        float l = length();
        return {x / l, y / l, z / l};
    }

    float Vector3::length() const {
        return sqrt(x * x + y * y + z * z);
    }

    Vector3 Vector3::rotate(Vector3 &euler) const {
        glm::vec3 rotated = glm::rotate(glm::quat(glm::vec3{euler.x, euler.y, euler.z}), glm::vec3{x, y, z});
        return Vector3{rotated.x, rotated.y, rotated.z};
    }

    Vector3 Vector3::operator+(const Vector3 &other) const {
        return {x + other.x, y + other.y, z + other.z};
    }

    Vector3 Vector3::operator-(const Vector3 &other) const {
        return {x - other.x, y - other.y, z - other.z};
    }

    Vector3 &Vector3::operator+=(const Vector3 &other) {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        return *this;
    }

    Vector3 &Vector3::operator-=(const Vector3 &other) {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
        return *this;
    }

    Vector3 Vector3::operator+(const float scalar) const {
        return {x + scalar, y + scalar, z + scalar};
    }

    Vector3 Vector3::operator-(const float scalar) const {
        return {x - scalar, y - scalar, z - scalar};
    }

    Vector3 Vector3::operator*(const float scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }

    Vector3 Vector3::operator/(const float scalar) const {
        return {x / scalar, y / scalar, z / scalar};
    }

    Vector3 operator+(const float scalar, const Vector3 &v) { return v + scalar; }
    Vector3 operator-(const float scalar, const Vector3 &v) { return v - scalar; }
    Vector3 operator*(const float scalar, const Vector3 &v) { return v * scalar; }
    Vector3 operator/(const float scalar, const Vector3 &v) { return v / scalar; }
}
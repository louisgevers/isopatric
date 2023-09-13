#include "Matrix.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace isopatric::math {

    // Create identity matrix
    Matrix4::Matrix4() : mMatrix(glm::mat4(1.0f)) {}

    // Create matrix from glm directly (private constructor)
    Matrix4::Matrix4(glm::mat4 matrix) : mMatrix(matrix) {}

    void Matrix4::translate(float x, float y, float z) {
        mMatrix = glm::translate(mMatrix, glm::vec3(x, y, z));
    }

    void Matrix4::translate(const Vector3 &v) {
        mMatrix = glm::translate(mMatrix, glm::vec3(v.x, v.y, v.z));
    }

    void Matrix4::rotate(float angle, float x, float y, float z) {
        mMatrix = glm::rotate(mMatrix, angle, glm::vec3(x, y, z));
    }

    void Matrix4::rotate(float angle, const Vector3 &v) {
        mMatrix = glm::rotate(mMatrix, angle, glm::vec3(v.x, v.y, v.z));
    }

    void Matrix4::scale(float x, float y, float z) {
        mMatrix = glm::scale(mMatrix, glm::vec3(x, y, z));
    }

    void Matrix4::scale(const Vector3 &v) {
        mMatrix = glm::scale(mMatrix, glm::vec3(v.x, v.y, v.z));
    }

    Matrix4 Matrix4::orthographic(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax) {
        return Matrix4{glm::ortho(xMin, xMax, yMin, yMax, zMin, yMax)};
    }

    Matrix4 Matrix4::perspective(float aspect, float fov, float zMin, float zMax) {
        return Matrix4{glm::perspective(fov, aspect, zMin, zMax)};
    }

    const float *Matrix4::getElements() const {
        return glm::value_ptr(mMatrix);
    }

    Vector3 Matrix4::operator*(const Vector3 &other) {
        auto result = mMatrix * glm::vec4(other.x, other.y, other.z, 1);
        return {result.x, result.y, result.z};
    }

    Matrix4 Matrix4::inverse() {
        return Matrix4{glm::inverse(mMatrix)};
    }
}

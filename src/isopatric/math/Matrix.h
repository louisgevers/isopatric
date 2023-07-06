#ifndef ISOPATRIC_ISOPATRIC_MATH_MATRIX_H
#define ISOPATRIC_ISOPATRIC_MATH_MATRIX_H

#include "Vector.h"

// TODO avoid GLM in header
// Avoiding abstract class, implementing directly with glm
#include <glm/glm.hpp>

namespace isopatric::math {

    class Matrix4 {
    public:
        Matrix4();

        void translate(float x, float y, float z);
        void translate(const Vector3 &v);

        void rotate(float angle, float x, float y, float z);
        void rotate(float angle, const Vector3 &v);

        void scale(float x, float y, float z);
        void scale(const Vector3 &v);

        const float *getElements() const;

        static Matrix4 orthographic(
                float xMin, float xMax,
                float yMin, float yMax,
                float zMin = 0.1f, float zMax = 100.0f);
        static Matrix4 perspective(float aspect, float fov = 0.7, float zMin = 0.1f, float zMax = 100.0f);

    private:
        explicit Matrix4(glm::mat4 matrix);
        glm::mat4 mMatrix;
    };
}

#endif //ISOPATRIC_ISOPATRIC_MATH_MATRIX_H

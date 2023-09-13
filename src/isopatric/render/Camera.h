#ifndef ISOPATRIC_SRC_ISOPATRIC_RENDER_CAMERA_H
#define ISOPATRIC_SRC_ISOPATRIC_RENDER_CAMERA_H

#include <isopatric/math/Matrix.h>
#include <isopatric/math/Vector.h>

namespace isopatric::render {
    class Camera {
    public:
        Camera(
                math::Vector3 position = {0.0, 0.0, 0.0},
                math::Vector3 orientation = {0.0, 0.0, 0.0}
        );

        math::Matrix4 &getViewProjectionMatrix();

        math::Vector3 getUpDirection();
        math::Vector3 getForwardDirection();
        math::Vector3 getRightDirection();
    private:
        math::Vector3 mPosition;
        math::Vector3 mOrientation;

        math::Matrix4 mViewProjectionMatrix;

        void updateMatrices();

    };
}

#endif //ISOPATRIC_SRC_ISOPATRIC_RENDER_CAMERA_H

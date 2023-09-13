#ifndef ISOPATRIC_SRC_ISOPATRIC_RENDER_CAMERA_H
#define ISOPATRIC_SRC_ISOPATRIC_RENDER_CAMERA_H

#include <isopatric/math/Matrix.h>

namespace isopatric::render {
    class Camera {
    public:
        Camera();

        math::Matrix4 &getViewProjectionMatrix();
    private:
        math::Matrix4 mViewProjectionMatrix;

        void updateMatrices();
    };
}

#endif //ISOPATRIC_SRC_ISOPATRIC_RENDER_CAMERA_H

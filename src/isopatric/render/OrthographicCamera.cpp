#include "OrthographicCamera.h"

#include <isopatric/math/Matrix.h>

namespace isopatric::render {
    OrthographicCamera::OrthographicCamera(float left, float right, float top, float bottom, math::Vector3 position,
                                           math::Vector3 orientation)
            : Camera(position, orientation), mLeft(left), mRight(right), mTop(top), mBottom(bottom) {
        updateMatrices();
    }

    void OrthographicCamera::updateProjectionMatrix() {
        mProjectionMatrix = math::Matrix4::orthographic(mLeft, mRight, mBottom, mTop, -1.0f, 1.0f);
    }
}

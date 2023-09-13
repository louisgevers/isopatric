#include "Camera.h"

namespace isopatric::render {
    Camera::Camera() {
        updateMatrices();
    }

    math::Matrix4 &Camera::getViewProjectionMatrix() {
        return mViewProjectionMatrix;
    }

    void Camera::updateMatrices() {
        // TODO: use proper arguments
        isopatric::math::Matrix4 view;
        view.translate(0.0f, 0.0f, -3.0f);
        auto projection = isopatric::math::Matrix4::perspective(800.0f / 600);
        mViewProjectionMatrix = projection * view;
    }
}

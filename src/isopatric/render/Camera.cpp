#include "Camera.h"

#include <isopatric/math/Math.h>

namespace isopatric::render {
    Camera::Camera(math::Vector3 position, math::Vector3 orientation)
            : mPosition(position), mOrientation(orientation) {
        updateMatrices();
    }

    math::Matrix4 &Camera::getViewProjectionMatrix() {
        return mViewProjectionMatrix;
    }

    void Camera::translate(const math::Vector3 &t) {
        mPosition += t;
        updateMatrices();
    }

    void Camera::rotate(const math::Vector3 &euler) {
        mOrientation += euler;
        const float pitchLimit = math::radians(89.0f);
        mOrientation.x = math::clip(mOrientation.x, -pitchLimit, pitchLimit);
        updateMatrices();
    }

    void Camera::updateMatrices() {
        auto view = math::Matrix4::lookAt(mPosition, mPosition + getForwardDirection(), getUpDirection());
        auto projection = isopatric::math::Matrix4::perspective(800.0f / 600);
        mViewProjectionMatrix = projection * view;
    }

    math::Vector3 Camera::getUpDirection() {
        return math::Vector3{0.0, 1.0, 0.0}.rotate(mOrientation);
    }

    math::Vector3 Camera::getForwardDirection() {
        return math::Vector3{0.0, 0.0, -1.0}.rotate(mOrientation);
    }

    math::Vector3 Camera::getRightDirection() {
        return math::Vector3{1.0, 0.0, 0.0}.rotate(mOrientation);
    }
}

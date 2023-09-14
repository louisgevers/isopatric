#include "PerspectiveCamera.h"

namespace isopatric::render {

    PerspectiveCamera::PerspectiveCamera(int screenWidth, int screenHeight, float fov, float zMin, float zMax,
                                         math::Vector3 position,
                                         math::Vector3 orientation)
            : mScreenWidth(screenWidth), mScreenHeight(screenHeight), mFov(fov), mZMin(zMin), mZMax(zMax),
              Camera(position, orientation) {
        updateMatrices();
    }

    void PerspectiveCamera::updateProjectionMatrix() {
        mProjectionMatrix = math::Matrix4::perspective((float) mScreenWidth / (float) mScreenHeight, mFov, mZMin,
                                                       mZMax);
    }

    void PerspectiveCamera::setScreenSize(int screenWidth, int screenHeight) {
        mScreenWidth = screenWidth;
        mScreenHeight = screenHeight;
        updateMatrices();
    }

    void PerspectiveCamera::setFov(float fov) {
        mFov = fov;
        updateMatrices();
    }

    float PerspectiveCamera::getFov() const {
        return mFov;
    }

    void PerspectiveCamera::setZMin(float zMin) {
        mZMin = zMin;
        updateMatrices();
    }

    float PerspectiveCamera::getZMin() const {
        return mZMin;
    }

    void PerspectiveCamera::setZMax(float zMax) {
        mZMax = zMax;
        updateMatrices();
    }

    float PerspectiveCamera::getZMax() const {
        return mZMax;
    }
}

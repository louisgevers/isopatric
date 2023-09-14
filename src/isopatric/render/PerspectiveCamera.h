#ifndef ISOPATRIC_PERSPECTIVECAMERA_H
#define ISOPATRIC_PERSPECTIVECAMERA_H

#include <isopatric/render/Camera.h>

namespace isopatric::render {

    const float DEFAULT_FOV = 0.7;
    const float DEFAULT_Z_MIN = 0.1;
    const float DEFAULT_Z_MAX = 100;

    class PerspectiveCamera : public Camera {
    public:
        explicit PerspectiveCamera(
                int screenWidth,
                int screenHeight,
                float fov = DEFAULT_FOV,
                float zMin = DEFAULT_Z_MIN,
                float zMax = DEFAULT_Z_MAX,
                math::Vector3 position = {0.0, 0.0, 0.0},
                math::Vector3 orientation = {0.0, 0.0, 0.0}
        );

        void setScreenSize(int screenWidth, int screenHeight);

        void setFov(float fov);

        float getFov() const;

        void setZMin(float zMin);

        float getZMin() const;

        void setZMax(float zMax);

        float getZMax() const;

    protected:
        void updateProjectionMatrix() override;

    private:
        int mScreenWidth;
        int mScreenHeight;
        float mFov;
        float mZMin;
        float mZMax;
    };
}

#endif //ISOPATRIC_PERSPECTIVECAMERA_H

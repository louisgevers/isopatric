#ifndef ISOPATRIC_ORTHOGRAPHICCAMERA_H
#define ISOPATRIC_ORTHOGRAPHICCAMERA_H

#include <isopatric/render/Camera.h>

namespace isopatric::render {
    class OrthographicCamera : public Camera {
    public:
        OrthographicCamera(float left, float right, float top, float bottom, math::Vector3 position,
                           math::Vector3 orientation);

    protected:
        void updateProjectionMatrix() override;

    private:
        float mLeft;
        float mRight;
        float mTop;
        float mBottom;
    };

}

#endif //ISOPATRIC_ORTHOGRAPHICCAMERA_H

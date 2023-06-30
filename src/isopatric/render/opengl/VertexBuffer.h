#ifndef ISOPATRIC_RENDER_OPENGL_VERTEXBUFFER_H
#define ISOPATRIC_RENDER_OPENGL_VERTEXBUFFER_H

#include <isopatric/render/VertexBuffer.h>

namespace isopatric::render {
    class GLVertexBuffer : public VertexBuffer {
    public:
        GLVertexBuffer(float *vertices, unsigned int size);

        ~GLVertexBuffer() override;

        void bind() override;

        void unbind() override;

    private:
        unsigned int mBufferId;
    };
}

#endif //ISOPATRIC_RENDER_OPENGL_VERTEXBUFFER_H

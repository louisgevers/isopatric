#ifndef ISOPATRIC_ISOPATRIC_RENDER_OPENGL_INDEXBUFFER_H
#define ISOPATRIC_ISOPATRIC_RENDER_OPENGL_INDEXBUFFER_H

#include <isopatric/render/IndexBuffer.h>

namespace isopatric::render {
    class GLIndexBuffer : public IndexBuffer {
    public:
        GLIndexBuffer(unsigned int *indices, unsigned int size);

        ~GLIndexBuffer() override;

        void bind() override;

        void unbind() override;

        unsigned int getCount() override;

    private:
        unsigned int mCount;
        unsigned int mBufferId;
    };
}
#endif //ISOPATRIC_ISOPATRIC_RENDER_OPENGL_INDEXBUFFER_H

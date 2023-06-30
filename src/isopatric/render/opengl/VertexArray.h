#ifndef ISOPATRIC_ISOPATRIC_RENDER_OPENGL_VERTEXARRAY_H
#define ISOPATRIC_ISOPATRIC_RENDER_OPENGL_VERTEXARRAY_H

#include <isopatric/render/VertexArray.h>

namespace isopatric::render {
    class GLVertexArray : public VertexArray {
    public:
        GLVertexArray();

        ~GLVertexArray() override;

        void bind() override;

        void unbind() override;

        void addVertexBuffer(Ref <VertexBuffer> &buffer) override;

        void setIndexBuffer(Ref <IndexBuffer> &buffer) override;

    private:
        unsigned int mVertexArrayId;
        std::vector<Ref<VertexBuffer>> mVertexBuffers;
        Ref<IndexBuffer> mIndexBuffer;
    };
}

#endif //ISOPATRIC_ISOPATRIC_RENDER_OPENGL_VERTEXARRAY_H

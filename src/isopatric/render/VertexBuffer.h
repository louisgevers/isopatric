#ifndef ISOPATRIC_RENDER_VERTEXBUFFER_H
#define ISOPATRIC_RENDER_VERTEXBUFFER_H

namespace isopatric::render {
    class VertexBuffer {
    public:
        virtual ~VertexBuffer() = default;

        virtual void bind() = 0;

        virtual void unbind() = 0;

        static Scope<VertexBuffer> create(float *vertices, unsigned int size);
    };
}

#endif //ISOPATRIC_RENDER_VERTEXBUFFER_H

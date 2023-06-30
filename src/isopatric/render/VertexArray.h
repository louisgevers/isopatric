#ifndef ISOPATRIC_ISOPATRIC_RENDER_VERTEXARRAY_H
#define ISOPATRIC_ISOPATRIC_RENDER_VERTEXARRAY_H

#include "IndexBuffer.h"
#include "VertexBuffer.h"

namespace isopatric::render {

    class VertexArray {
    public:
        virtual ~VertexArray() = default;

        virtual void bind() = 0;

        virtual void unbind() = 0;

        virtual void addVertexBuffer(Ref <VertexBuffer> &buffer) = 0;

        virtual void setIndexBuffer(Ref <IndexBuffer> &buffer) = 0;

        static Scope <VertexArray> create();
    };
}
#endif //ISOPATRIC_ISOPATRIC_RENDER_VERTEXARRAY_H

#ifndef ISOPATRIC_ISOPATRIC_RENDER_INDEXBUFFER_H
#define ISOPATRIC_ISOPATRIC_RENDER_INDEXBUFFER_H

namespace isopatric::render {
    class IndexBuffer {
    public:
        virtual ~IndexBuffer() = default;

        virtual void bind() = 0;

        virtual void unbind() = 0;

        virtual unsigned int getCount() = 0;

        static Scope <IndexBuffer> create(unsigned int *indices, unsigned int size);
    };
}

#endif //ISOPATRIC_ISOPATRIC_RENDER_INDEXBUFFER_H

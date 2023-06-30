#include "IndexBuffer.h"

#include <glad/glad.h>

namespace isopatric::render {

    Scope <IndexBuffer> IndexBuffer::create(unsigned int *indices, unsigned int size) {
        return createScope<GLIndexBuffer>(indices, size);
    }

    GLIndexBuffer::GLIndexBuffer(unsigned int *indices, unsigned int size)
            : mCount(size) {
        glGenBuffers(1, &mBufferId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW); // TODO different usages
    }

    GLIndexBuffer::~GLIndexBuffer() {
        glDeleteBuffers(1, &mBufferId);
    }

    void GLIndexBuffer::bind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferId);
    }

    void GLIndexBuffer::unbind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    unsigned int GLIndexBuffer::getCount() {
        return mCount;
    }
}

#include "VertexBuffer.h"

#include <glad/glad.h>

namespace isopatric::render {

    Scope <VertexBuffer> VertexBuffer::create(float *vertices, unsigned int size) {
        return createScope<GLVertexBuffer>(vertices, size);
    }

    GLVertexBuffer::GLVertexBuffer(float *vertices, unsigned int size) {
        glGenBuffers(1, &mBufferId);
        glBindBuffer(GL_ARRAY_BUFFER, mBufferId);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW); // TODO usage might change
    }

    GLVertexBuffer::~GLVertexBuffer() {
        glDeleteBuffers(1, &mBufferId);
    }

    void GLVertexBuffer::bind() {
        glBindBuffer(GL_ARRAY_BUFFER, mBufferId);
    }

    void GLVertexBuffer::unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

}
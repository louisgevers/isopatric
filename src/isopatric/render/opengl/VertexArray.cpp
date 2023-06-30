#include "VertexArray.h"

#include <glad/glad.h>

namespace isopatric::render {
    static GLenum shaderDataTypeToGLType(ShaderDataType type) {
        switch (type) {
            case ShaderDataType::Float:
            case ShaderDataType::Float2:
            case ShaderDataType::Float3:
            case ShaderDataType::Float4:
            case ShaderDataType::Mat3:
            case ShaderDataType::Mat4:
                return GL_FLOAT;
            case ShaderDataType::Int:
            case ShaderDataType::Int2:
            case ShaderDataType::Int3:
            case ShaderDataType::Int4:
                return GL_INT;
            case ShaderDataType::Bool:
                return GL_BOOL;
            case ShaderDataType::None:
                break;
        }
        ASSERT(false, "Unknown shader data type (OpenGL)");
        return 0;
    }

    Scope <VertexArray> VertexArray::create() {
        return createScope<GLVertexArray>();
    }

    GLVertexArray::GLVertexArray() {
        glGenVertexArrays(1, &mVertexArrayId);
    }

    GLVertexArray::~GLVertexArray() {
        glDeleteVertexArrays(1, &mVertexArrayId);
    }

    void GLVertexArray::bind() {
        glBindVertexArray(mVertexArrayId);
    }

    void GLVertexArray::unbind() {
        glBindVertexArray(0);
    }

    void GLVertexArray::addVertexBuffer(Ref <VertexBuffer> &buffer) {
        ASSERT(!buffer->getLayout().getAttributes().empty(), "Vertex buffer has no layout!")

        glBindVertexArray(mVertexArrayId);
        buffer->bind();

        VertexBufferLayout &layout = buffer->getLayout();
        int index = 0;
        for (auto &attribute: layout.getAttributes()) {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(
                    index,
                    attribute.getComponentCount(),
                    shaderDataTypeToGLType(attribute.type),
                    attribute.normalized ? GL_TRUE : GL_FALSE,
                    layout.getStride(),
                    (void *) (uintptr_t) attribute.offset);
            index++;
        }

        mVertexBuffers.push_back(buffer);
    }

    void GLVertexArray::setIndexBuffer(Ref <IndexBuffer> &buffer) {
        glBindVertexArray(mVertexArrayId);
        buffer->bind();
        mIndexBuffer = buffer;
    }
}

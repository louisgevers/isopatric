#include "RendererAPI.h"

#include <glad/glad.h>

namespace isopatric::render {

    Scope <RendererAPI> RendererAPI::create() {
        return createScope<GLRendererAPI>();
    }

    GLRendererAPI::GLRendererAPI() = default;
    GLRendererAPI::~GLRendererAPI() = default;

    void GLRendererAPI::init() {
        glEnable(GL_DEPTH_TEST);
    }

    void GLRendererAPI::clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void GLRendererAPI::setClearColor(float red, float green, float blue, float alpha) {
        glClearColor(red, green, blue, alpha);
    }

    void GLRendererAPI::drawIndexed(const Ref <VertexArray> &vertexArray) {
        glDrawElements(GL_TRIANGLES, vertexArray->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);
    }

    void GLRendererAPI::setViewPort(int x, int y, int width, int height) {
        glViewport(x, y, width, height);
    }
}

#include "Renderer.h"

#include <isopatric/render/RenderCommand.h>

namespace isopatric::render {

    void Renderer::beginScene() {}

    void Renderer::submit(const Ref <Shader> &shader, const Ref <VertexArray> &vertexArray) {
        shader->bind();
        vertexArray->bind();
        RenderCommand::drawIndexed(vertexArray);
    }

    void Renderer::endScene() {}

    void Renderer::onWindowResize(int width, int height) {
        RenderCommand::setViewPort(0, 0, width, height);
    }
}

#ifndef ISOPATRIC_RENDER_RENDERER_H
#define ISOPATRIC_RENDER_RENDERER_H

#include <isopatric/render/Shader.h>
#include <isopatric/render/VertexArray.h>

namespace isopatric::render {

    class Renderer {
    public:
        Renderer() = default;
        ~Renderer() = default;

        void beginScene();
        void submit(const Ref <Shader> &shader, const Ref <VertexArray> &vertexArray);
        void endScene();

        void onWindowResize(int width, int height);
    };
}

#endif //ISOPATRIC_RENDER_RENDERER_H

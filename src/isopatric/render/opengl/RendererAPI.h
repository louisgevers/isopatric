#ifndef ISOPATRIC_ISOPATRIC_RENDER_OPENGL_RENDERERAPI_H
#define ISOPATRIC_ISOPATRIC_RENDER_OPENGL_RENDERERAPI_H

#include <isopatric/render/RendererAPI.h>

namespace isopatric::render {

    class GLRendererAPI : public RendererAPI {
    public:
        GLRendererAPI();
        ~GLRendererAPI() override;

        void init() override;

        void clear() override;
        void setClearColor(float red, float green, float blue, float alpha) override;

        void drawIndexed(const Ref <VertexArray> &vertexArray) override;

        void setViewPort(int x, int y, int width, int height) override;
    };
}

#endif //ISOPATRIC_ISOPATRIC_RENDER_OPENGL_RENDERERAPI_H

#ifndef ISOPATRIC_RENDER_RENDERERAPI_H
#define ISOPATRIC_RENDER_RENDERERAPI_H

#include <isopatric/render/VertexArray.h>

namespace isopatric::render {
    class RendererAPI {
    public:
        virtual ~RendererAPI() = default;

        virtual void init() = 0;
        virtual void clear() = 0;
        virtual void setClearColor(float red, float green, float blue, float alpha) = 0;

        virtual void drawIndexed(const Ref <VertexArray> &vertexArray) = 0;

        virtual void setViewPort(int x, int y, int width, int height) = 0;

        static Scope <RendererAPI> create();
    };
}

#endif //ISOPATRIC_RENDER_RENDERERAPI_H

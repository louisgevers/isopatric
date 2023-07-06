#ifndef ISOPATRIC_RENDER_RENDERCOMMAND_H
#define ISOPATRIC_RENDER_RENDERCOMMAND_H

#include <isopatric/render/RendererAPI.h>

namespace isopatric::render {
    class RenderCommand {
    public:
        static inline void init() {
            sRendererAPI->init();
        }

        static inline void clear() {
            sRendererAPI->clear();
        }

        static inline void setClearColor(float red, float green, float blue, float alpha) {
            sRendererAPI->setClearColor(red, green, blue, alpha);
        }

        static inline void drawIndexed(const Ref<VertexArray> &vertexArray) {
            sRendererAPI->drawIndexed(vertexArray);
        }

        static inline void setViewPort(int x, int y, int width, int height) {
            sRendererAPI->setViewPort(x, y, width, height);
        }

    private:
        const static inline Scope<RendererAPI> sRendererAPI{RendererAPI::create()};
    };
}

#endif //ISOPATRIC_RENDER_RENDERCOMMAND_H

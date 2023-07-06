#ifndef ISOPATRIC_ISOPATRIC_RENDER_OPENGL_TEXTURE_H
#define ISOPATRIC_ISOPATRIC_RENDER_OPENGL_TEXTURE_H

#include <isopatric/render/Texture.h>

namespace isopatric::render {
    class GLTexture : public Texture {
    public:
        GLTexture(const std::string &filePath, TextureSpecification spec);
        ~GLTexture() override;

        int getWidth() const override;
        int getHeight() const override;

    protected:
        void doBind(int textureUnit) const override;

    private:
        int mWidth;
        int mHeight;
        int mChannels;
        unsigned int mTexture;
    };
}

#endif //ISOPATRIC_ISOPATRIC_RENDER_OPENGL_TEXTURE_H

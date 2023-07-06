#ifndef ISOPATRIC_ISOPATRIC_RENDER_TEXTURE_H
#define ISOPATRIC_ISOPATRIC_RENDER_TEXTURE_H

namespace isopatric::render {
    enum class ImageFormat {
        RGB, RGBA,
    };

    struct TextureSpecification {
        const ImageFormat imageFormat = ImageFormat::RGBA;
        const bool generateMipMaps = true;
    };

    class Texture {
    public:
        virtual ~Texture() = default;

        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;

        void bind(int textureUnit = 0) const {
            doBind(textureUnit);
        }

        static Scope<Texture> create(
                const std::string &filePath,
                TextureSpecification spec = TextureSpecification{}
        );

    protected:
        virtual void doBind(int textureUnit) const = 0;
    };
}

#endif //ISOPATRIC_ISOPATRIC_RENDER_TEXTURE_H

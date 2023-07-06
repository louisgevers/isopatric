#include "Texture.h"

#include <stb_image.h>
#include <glad/glad.h>

namespace isopatric::render {
    static inline int imageFormatToGLFormat(ImageFormat format) {
        switch (format) {
            case ImageFormat::RGB:
                return GL_RGB;
            case ImageFormat::RGBA:
                return GL_RGBA;
        }
    }

    Scope <Texture> Texture::create(const std::string &filePath, const TextureSpecification spec) {
        return createScope<GLTexture>(filePath, spec);
    }

    GLTexture::GLTexture(const std::string &filePath, const TextureSpecification spec) {
        // Flip y-axis as opengl 0.0 is bottom
        stbi_set_flip_vertically_on_load(true);
        // Load texture image
        int width, height, channels;
        unsigned char *data = stbi_load(filePath.c_str(), &width, &height, &channels, 0);
        ASSERT(data, "Could not load image: {}", filePath)
        mWidth = width;
        mHeight = height;
        mChannels = channels;

        // Generate texture
        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        mTexture = texture;

        // Attach image and create the mipmaps
        int format = imageFormatToGLFormat(spec.imageFormat);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        if (spec.generateMipMaps) {
            glGenerateMipmap(GL_TEXTURE_2D);
        }

        // Wrapping/filtering options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // No longer needed
        stbi_image_free(data);
    }

    GLTexture::~GLTexture() {
        glDeleteTextures(1, &mTexture);
    }

    int GLTexture::getWidth() const {
        return mWidth;
    }

    int GLTexture::getHeight() const {
        return mHeight;
    }

    void GLTexture::doBind(int textureUnit) const {
        glActiveTexture(GL_TEXTURE0 + textureUnit);
        glBindTexture(GL_TEXTURE_2D, mTexture);
    }
}
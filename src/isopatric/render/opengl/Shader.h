#ifndef ISOPATRIC_ISOPATRIC_RENDER_OPENGL_SHADER_H
#define ISOPATRIC_ISOPATRIC_RENDER_OPENGL_SHADER_H

#include <isopatric/render/Shader.h>

namespace isopatric::render {

    class GLShader : public Shader {
    public:
        GLShader(const std::string &vertexSrc, const std::string &fragmentSrc);

        ~GLShader() override;

        void bind() override;

        void unbind() override;

    private:
        unsigned int mShaderProgramId;
    };

}

#endif //ISOPATRIC_ISOPATRIC_RENDER_OPENGL_SHADER_H

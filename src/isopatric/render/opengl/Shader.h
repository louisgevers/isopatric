#ifndef ISOPATRIC_ISOPATRIC_RENDER_OPENGL_SHADER_H
#define ISOPATRIC_ISOPATRIC_RENDER_OPENGL_SHADER_H

#include <isopatric/render/Shader.h>

namespace isopatric::render {

    class GLShader : public Shader {
    public:
        GLShader(const std::string &filePath);
        GLShader(const std::string &vertexSrc, const std::string &fragmentSrc);
        ~GLShader() override;

        void bind() override;
        void unbind() override;

        void setBool(const std::string &name, bool value) const override;
        void setInt(const std::string &name, int value) const override;
        void setFloat(const std::string &name, float value) const override;

        void setMatrix4(const std::string &name, math::Matrix4 &value) const override;
    private:
        unsigned int mShaderProgramId;
        void compileProgram(const std::string &vertexSrc, const std::string &fragmentSrc);
    };

}

#endif //ISOPATRIC_ISOPATRIC_RENDER_OPENGL_SHADER_H

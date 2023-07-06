#ifndef ISOPATRIC_ISOPATRIC_RENDER_SHADER_H
#define ISOPATRIC_ISOPATRIC_RENDER_SHADER_H

#include <isopatric/math/Matrix.h>

namespace isopatric::render {

    class Shader {
    public:
        virtual ~Shader() = default;

        virtual void bind() = 0;
        virtual void unbind() = 0;

        virtual void setBool(const std::string &name, bool value) const = 0;
        virtual void setInt(const std::string &name, int value) const = 0;
        virtual void setFloat(const std::string &name, float value) const = 0;

        virtual void setMatrix4(const std::string &name, math::Matrix4 &value) const = 0;

        static Scope <Shader> create(const std::string &filePath);
        static Scope <Shader> create(const std::string &vertexSrc, const std::string &fragmentSrc);
    };
}

#endif //ISOPATRIC_ISOPATRIC_RENDER_SHADER_H

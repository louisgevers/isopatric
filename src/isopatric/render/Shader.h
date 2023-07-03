#ifndef ISOPATRIC_ISOPATRIC_RENDER_SHADER_H
#define ISOPATRIC_ISOPATRIC_RENDER_SHADER_H

namespace isopatric::render {

    class Shader {
    public:
        virtual ~Shader() = default;

        virtual void bind() = 0;

        virtual void unbind() = 0;

        static Scope <Shader> create(const std::string &vertexSrc, const std::string &fragmentSrc);
    };
}

#endif //ISOPATRIC_ISOPATRIC_RENDER_SHADER_H

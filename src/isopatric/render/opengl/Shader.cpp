#include "Shader.h"

#include <glad/glad.h>

namespace isopatric::render {

    static inline void verifyShaderCompilation(unsigned int shader, const char *type) {
        GLint isCompiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
        if (isCompiled == GL_FALSE) {
            GLint maxLength = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

            glDeleteShader(shader);

            LOG_ERROR(infoLog.data());
            ASSERT(false, "{} shader compilation failure!", type);
        }
    }

    Scope <Shader> Shader::create(const std::string &vertexSrc, const std::string &fragmentSrc) {
        return createScope<GLShader>(vertexSrc, fragmentSrc);
    }

    GLShader::GLShader(const std::string &vertexSrc, const std::string &fragmentSrc) {
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        const GLchar *source = vertexSrc.c_str();
        glShaderSource(vertexShader, 1, &source, nullptr);
        glCompileShader(vertexShader);
        verifyShaderCompilation(vertexShader, "Vertex");

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        source = fragmentSrc.c_str();
        glShaderSource(fragmentShader, 1, &source, nullptr);
        glCompileShader(fragmentShader);
        verifyShaderCompilation(fragmentShader, "Fragment");

        mShaderProgramId = glCreateProgram();
        glAttachShader(mShaderProgramId, vertexShader);
        glAttachShader(mShaderProgramId, fragmentShader);
        glLinkProgram(mShaderProgramId);

        // Verify linking
        GLint isLinked = 0;
        glGetProgramiv(mShaderProgramId, GL_LINK_STATUS, &isLinked);
        if (isLinked == GL_FALSE) {
            GLint maxLength = 0;
            glGetProgramiv(mShaderProgramId, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(mShaderProgramId, maxLength, &maxLength, &infoLog[0]);

            glDeleteProgram(mShaderProgramId);
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            LOG_ERROR(infoLog.data());
            ASSERT(false, "Shader link failure!");
            return;
        }

        // Don't need these anymore
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    GLShader::~GLShader() {
        glDeleteProgram(mShaderProgramId);
    }

    void GLShader::bind() {
        glUseProgram(mShaderProgramId);
    }

    void GLShader::unbind() {
        glUseProgram(0);
    }
}

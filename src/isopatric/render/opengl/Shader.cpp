#include "Shader.h"

#include <isopatric/file/AssetReader.h>

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

    Scope <Shader> Shader::create(const std::string &filePath) {
        return createScope<GLShader>(filePath);
    }

    Scope <Shader> Shader::create(const std::string &vertexSrc, const std::string &fragmentSrc) {
        return createScope<GLShader>(vertexSrc, fragmentSrc);
    }

    GLShader::GLShader(const std::string &filePath) {
        // Single source contains both vertex and fragment source
        std::string vertexSrc = file::AssetReader::readBinary(filePath);

        // Create a copy for the fragment source
        std::string fragmentSrc = vertexSrc;

        // Append after first line containing version
        size_t eol = vertexSrc.find_first_of("\r\n");
        ASSERT(eol != std::string::npos, "Shader syntax error, no new line.")

        // Add definition to separate vertex and fragment sources
        vertexSrc.insert(eol + 1, "#define VERTEX_SHADER\n");
        fragmentSrc.insert(eol + 1, "#define FRAGMENT_SHADER\n");

        // Compile sources
        compileProgram(vertexSrc, fragmentSrc);
    }

    GLShader::GLShader(const std::string &vertexSrc, const std::string &fragmentSrc) {
        compileProgram(vertexSrc, fragmentSrc);
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

    void GLShader::compileProgram(const std::string &vertexSrc, const std::string &fragmentSrc) {
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

    void GLShader::setBool(const std::string &name, bool value) const {
        glUniform1i(glGetUniformLocation(mShaderProgramId, name.c_str()), (int) value);
    }

    void GLShader::setInt(const std::string &name, int value) const {
        glUniform1i(glGetUniformLocation(mShaderProgramId, name.c_str()), value);
    }

    void GLShader::setFloat(const std::string &name, float value) const {
        glUniform1f(glGetUniformLocation(mShaderProgramId, name.c_str()), value);
    }

    void GLShader::setMatrix4(const std::string &name, math::Matrix4 &value) const {
        int location = glGetUniformLocation(mShaderProgramId, name.c_str());
        glUniformMatrix4fv(location, 1, GL_FALSE, value.getElements());
    }
}

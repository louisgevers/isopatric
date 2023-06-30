#include <isopatric/isopatric.h>

#include <imgui.h>

// TODO: temporary for experimenting with OpenGL
#include <glad/glad.h>


class OpenGLExperimentLayer : public isopatric::core::Layer {
public:
    void onAttach() override {
        const char *vertexShaderSource = "#version 330 core\n"
                                         "layout (location = 0) in vec3 aPos;\n"
                                         "layout (location = 1) in vec3 aColor;\n"
                                         "out vec3 myColor;\n"
                                         "void main()\n"
                                         "{\n"
                                         "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                         "   myColor = aColor;\n"
                                         "}\0";
        const char *fragmentShaderSource = "#version 330 core\n"
                                           "in vec3 myColor;\n"
                                           "out vec4 FragColor;\n"
                                           "void main()\n"
                                           "{\n"
                                           "   FragColor = vec4(myColor, 1.0f);\n"
                                           "}\n\0";
        // Vertex shader
        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
        glCompileShader(vertexShader);

        // Fragment shader
        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
        glCompileShader(fragmentShader);

        // Link into shader program
        mShaderProgram = glCreateProgram();
        glAttachShader(mShaderProgram, vertexShader);
        glAttachShader(mShaderProgram, fragmentShader);
        glLinkProgram(mShaderProgram);
        // Don't need these anymore
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        // 2 triangle vertices for a rectangle
        float vertices[] = {
                0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
                0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
                -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
                -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f,
        };
        // Shared indices
        unsigned int indices[] = {
                0, 1, 3,
                1, 2, 3
        };

        // Create vertex array object
        mVertexArray = isopatric::render::VertexArray::create();

        // Create vertex buffer
        mVertexBuffer = isopatric::render::VertexBuffer::create(vertices, sizeof(vertices));
        isopatric::render::VertexBufferLayout bufferLayout = {
                {isopatric::render::ShaderDataType::Float3},
                {isopatric::render::ShaderDataType::Float3}
        };
        mVertexBuffer->setLayout(bufferLayout);
        mVertexArray->addVertexBuffer(mVertexBuffer);

        // Create index buffer
        mIndexBuffer = isopatric::render::IndexBuffer::create(indices, sizeof(indices));
        mVertexArray->setIndexBuffer(mIndexBuffer);
    }

    void onUpdate() override {
        // Dark background
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw with shader program
        glUseProgram(mShaderProgram);
        mVertexArray->bind();
//        glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, mIndexBuffer->getCount(), GL_UNSIGNED_INT, 0);
        mVertexArray->unbind();
    }

private:
    unsigned int mShaderProgram{};
    std::unique_ptr<isopatric::render::VertexArray> mVertexArray;
    std::shared_ptr<isopatric::render::VertexBuffer> mVertexBuffer;
    std::shared_ptr<isopatric::render::IndexBuffer> mIndexBuffer;
};

class TestLayer : public isopatric::core::Layer {
public:
    void onUIRender() override {
        ImGui::Begin("Test");
        ImGui::Text("Hello");
        ImGui::Button("Click me");
        ImGui::End();
    };
};

class PlayGround : public isopatric::core::Application {
public:
    PlayGround() {
        pushOverlay(new TestLayer());
        pushLayer(new OpenGLExperimentLayer());
    }
};

isopatric::core::Application *isopatric::core::createApplication() {
    return new PlayGround();
}
#include <isopatric/isopatric.h>

#include <imgui.h>

// TODO: temporary for experimenting with OpenGL
#include <glad/glad.h>


class OpenGLExperimentLayer : public isopatric::core::Layer {
public:
    void onAttach() override {
        const char *vertexShaderSource = "#version 330 core\n"
                                         "layout (location = 0) in vec3 aPos;\n"
                                         "void main()\n"
                                         "{\n"
                                         "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                         "}\0";
        const char *fragmentShaderSource = "#version 330 core\n"
                                           "out vec4 FragColor;\n"
                                           "void main()\n"
                                           "{\n"
                                           "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
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
                0.5f, 0.5f, 0.0f,
                0.5f, -0.5f, 0.0f,
                -0.5f, -0.5f, 0.0f,
                -0.5f, 0.5f, 0.0f
        };
        // Shared indices
        unsigned int indices[] = {
                0, 1, 3,
                1, 2, 3
        };

        // Create vertex array object
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        // Create buffers
        mVertexBuffer = isopatric::render::VertexBuffer::create(vertices, sizeof(vertices));
        mIndexBuffer = isopatric::render::IndexBuffer::create(indices, sizeof(indices));

        // Linking vertex attributes
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);

        // Done with configuring the VBO, can safely unbind vertex buffer, NOT index buffer
        mVertexBuffer->unbind();
    }

    void onUpdate() override {
        // Dark background
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw with shader program
        glUseProgram(mShaderProgram);
        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, mIndexBuffer->getCount(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

private:
    unsigned int mShaderProgram{};
    unsigned int VAO{};
    std::unique_ptr<isopatric::render::VertexBuffer> mVertexBuffer;
    std::unique_ptr<isopatric::render::IndexBuffer> mIndexBuffer;
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
#include <isopatric/isopatric.h>

#include <imgui.h>

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

        // Compile the shaders
        mShader = isopatric::render::Shader::create(vertexShaderSource, fragmentShaderSource);

        // Create vertex array object
        mVertexArray = isopatric::render::VertexArray::create();

        // Create vertex buffer
        std::shared_ptr<isopatric::render::VertexBuffer> vertexBuffer;
        vertexBuffer = isopatric::render::VertexBuffer::create(vertices, sizeof(vertices));
        isopatric::render::VertexBufferLayout bufferLayout = {
                {isopatric::render::ShaderDataType::Float3},
                {isopatric::render::ShaderDataType::Float3}
        };
        vertexBuffer->setLayout(bufferLayout);
        mVertexArray->addVertexBuffer(vertexBuffer);

        // Create index buffer
        std::shared_ptr<isopatric::render::IndexBuffer> indexBuffer;
        indexBuffer = isopatric::render::IndexBuffer::create(indices, sizeof(indices));
        mVertexArray->setIndexBuffer(indexBuffer);
    }

    void onUpdate() override {
        // Dark background
        isopatric::render::RenderCommand::setClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        isopatric::render::RenderCommand::clear();

        // Draw with shader program
        renderer.beginScene();
        renderer.submit(mShader, mVertexArray);
        renderer.endScene();
    }

    void onEvent(isopatric::event::Event &event) override {
        isopatric::event::EventDispatcher dispatcher{event};
        dispatcher.dispatch<isopatric::event::WindowResizeEvent>(BIND_FN(onWindowResize));
    }

    bool onWindowResize(isopatric::event::WindowResizeEvent &event) {
        renderer.onWindowResize(event.getWidth(), event.getHeight());
        return false;
    }

private:
    isopatric::render::Renderer renderer{};
    std::shared_ptr<isopatric::render::Shader> mShader;
    std::shared_ptr<isopatric::render::VertexArray> mVertexArray;
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
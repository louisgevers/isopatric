#include <isopatric/isopatric.h>

#include <imgui.h>

class OpenGLExperimentLayer : public isopatric::core::Layer {
public:
    void onAttach() override {
        // 2 triangle vertices for a rectangle
        float vertices[] = {
                // vec3 position - vec3 color - vec2 tex coord
                0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
                0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
                -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
                -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f,
        };
        // Shared indices
        unsigned int indices[] = {
                0, 1, 3,
                1, 2, 3
        };

        // Compile the shaders
        mShader = isopatric::render::Shader::create("assets/shaders/Base.glsl");

        // Create vertex array object
        mVertexArray = isopatric::render::VertexArray::create();

        // Create vertex buffer
        std::shared_ptr<isopatric::render::VertexBuffer> vertexBuffer;
        vertexBuffer = isopatric::render::VertexBuffer::create(vertices, sizeof(vertices));
        isopatric::render::VertexBufferLayout bufferLayout = {
                {isopatric::render::ShaderDataType::Float3},
                {isopatric::render::ShaderDataType::Float3},
                {isopatric::render::ShaderDataType::Float2},
        };
        vertexBuffer->setLayout(bufferLayout);
        mVertexArray->addVertexBuffer(vertexBuffer);

        // Create index buffer
        std::shared_ptr<isopatric::render::IndexBuffer> indexBuffer;
        indexBuffer = isopatric::render::IndexBuffer::create(indices, sizeof(indices));
        mVertexArray->setIndexBuffer(indexBuffer);

        // Create textures
        mTexture1 = isopatric::render::Texture::create("assets/textures/container.jpg",
                                                       {isopatric::render::ImageFormat::RGB});
        mTexture2 = isopatric::render::Texture::create("assets/textures/awesomeface.png");

        // Texture units to shader
        mShader->bind();
        mShader->setInt("myTexture1", 0);
        mShader->setInt("myTexture2", 1);
    }

    void onUpdate() override {
        // Dark background
        isopatric::render::RenderCommand::setClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        isopatric::render::RenderCommand::clear();

        // Bind textures on corresponding texture units
        mTexture1->bind(0);
        mTexture2->bind(1);

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
    std::unique_ptr<isopatric::render::Texture> mTexture1;
    std::unique_ptr<isopatric::render::Texture> mTexture2;
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
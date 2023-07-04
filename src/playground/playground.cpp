#include <isopatric/isopatric.h>

#include <imgui.h>

// TODO: remove when textures are implemented
#include <stb_image.h>
#include <glad/glad.h>

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

        // --- BEGIN TEXTURES ---

        // --- Texture 1 ---
        // Flip y-axis as opengl 0.0 is bottom
        stbi_set_flip_vertically_on_load(true);
        // Load texture image
        int width, height, nChannels;
        unsigned char *data = stbi_load("assets/textures/container.jpg", &width, &height, &nChannels, 0);
        if (!data) {
            LOG_ERROR("Failed to load texture.");
        }

        // Generate texture
        glGenTextures(1, &mTexture1);
        glBindTexture(GL_TEXTURE_2D, mTexture1);
        // Attach image and create the mipmaps
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        // Wrapping/filtering options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // No longer needed
        stbi_image_free(data);

        // --- Texture 2 ---
        // Load texture image
        data = stbi_load("assets/textures/awesomeface.png", &width, &height, &nChannels, 0);
        if (!data) {
            LOG_ERROR("Failed to load texture.");
        }

        // Generate texture
        glGenTextures(1, &mTexture2);
        glBindTexture(GL_TEXTURE_2D, mTexture2);
        // Attach image (RGBA!) and create the mipmaps
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        // Wrapping/filtering options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // No longer needed
        stbi_image_free(data);

        // Texture units to shader
        mShader->bind();
        mShader->setInt("myTexture1", 0);
        mShader->setInt("myTexture2", 1);

        // --- END TEXTURES ---
    }

    void onUpdate() override {
        // Dark background
        isopatric::render::RenderCommand::setClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        isopatric::render::RenderCommand::clear();

        // Bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, mTexture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, mTexture2);

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
    unsigned int mTexture1;
    unsigned int mTexture2;
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
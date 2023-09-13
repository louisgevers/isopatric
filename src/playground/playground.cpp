#include <isopatric/isopatric.h>

#include <imgui.h>

class OpenGLExperimentLayer : public isopatric::core::Layer {
public:
    void onAttach() override {
        // Initialize input handling
        mInput = isopatric::input::Input::create();

        // Cube (vec3 position - vec3 color - vec3 tex coord
        float vertices[] = {
                // Face 1
                -0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
                0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
                0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
                // Face 2
                0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
                0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
                0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
                // Face 3
                -0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
                0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
                0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
                // Face 4
                -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
                0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
                0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
                // Face 5
                -0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
                -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
                -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
                // Face 6
                -0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
                0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
                0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
        };
        // Shared indices
        unsigned int indices[] = {
                // Face 1
                0, 1, 2,
                0, 2, 3,
                // Face 2
                4, 5, 6,
                4, 6, 7,
                // Face 3
                8, 9, 10,
                8, 10, 11,
                // Face 4
                12, 13, 14,
                12, 14, 15,
                // Face 5
                16, 17, 18,
                16, 18, 19,
                // Face 6
                20, 21, 22,
                20, 22, 23,
        };


//        // 2 triangle vertices for a rectangle
//        float vertices[] = {
//                // vec3 position - vec3 color - vec2 tex coord
//                0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
//                0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
//                -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
//                -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f,
//        };
//        // Shared indices
//        unsigned int indices[] = {
//                0, 1, 3,
//                1, 2, 3
//        };

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

        // Transform matrix -> to world space
        isopatric::math::Matrix4 transform;
        transform.rotate(mAngle, 1.0f, 0.0f, 0.0f);
        transform.rotate(0.7, 0.0f, 0.5f, 0.5f);
        transform.scale(0.5f, 0.5f, 0.5f);
        // Give them to the shader
        mShader->setMatrix4("transform", transform);

        // Bind textures on corresponding texture units
        mTexture1->bind(0);
        mTexture2->bind(1);

        // Draw with shader program
        renderer.beginScene(camera);
        renderer.submit(mShader, mVertexArray);
        renderer.endScene();
    }

    void onEvent(isopatric::event::Event &event) override {
        isopatric::event::EventDispatcher dispatcher{event};
        dispatcher.dispatch<isopatric::event::WindowResizeEvent>(BIND_FN(onWindowResize));
        dispatcher.dispatch<isopatric::event::KeyPressedEvent>(BIND_FN(onKeyPressed));
        dispatcher.dispatch<isopatric::event::MouseMovedEvent>(BIND_FN(onMouseMoved));
    }

    bool onWindowResize(isopatric::event::WindowResizeEvent &event) {
        renderer.onWindowResize(event.getWidth(), event.getHeight());
        return false;
    }

    bool onKeyPressed(isopatric::event::KeyPressedEvent &event) {
        const float magnitude = 0.1f;
        switch (event.getKeyCode()) {
            case isopatric::input::UpArrow:
                camera.translate(magnitude * camera.getUpDirection());
                break;
            case isopatric::input::DownArrow:
                camera.translate(-magnitude * camera.getUpDirection());
                break;
            case isopatric::input::LeftArrow:
                camera.translate(-magnitude * camera.getRightDirection());
                break;
            case isopatric::input::RightArrow:
                camera.translate(magnitude * camera.getRightDirection());
                break;
            default:
                break;
        }
        return false;
    }

    bool onMouseMoved(isopatric::event::MouseMovedEvent &event) {
        if (mInput->isMouseButtonPressed(isopatric::input::MouseCode::MouseLeft)) {
            const float magnitude = 0.005f;
            // Move along x to rotate around y and vice versa
            const isopatric::math::Vector3 rotation{(float) event.getMouseY(), (float) event.getMouseX(), 0.0};
            camera.rotate(magnitude * rotation);
        }
        return false;
    }

    void onUIRender() override {
        ImGui::Begin("Debug");
        ImGui::SliderFloat("Box angle", &mAngle, -3.14f, 3.14f);
        ImGui::End();
    };

private:
    isopatric::render::Renderer renderer{};
    isopatric::render::Camera camera{{0.0,   0.0, 3.0},
                                     {-0.14, 0.0, 0.0}};
    std::unique_ptr<isopatric::input::Input> mInput;
    std::shared_ptr<isopatric::render::Shader> mShader;
    std::shared_ptr<isopatric::render::VertexArray> mVertexArray;
    std::unique_ptr<isopatric::render::Texture> mTexture1;
    std::unique_ptr<isopatric::render::Texture> mTexture2;
    float mAngle{0.0f};
};

class PlayGround : public isopatric::core::Application {
public:
    PlayGround() {
        pushLayer(new OpenGLExperimentLayer());
    }
};

isopatric::core::Application *isopatric::core::createApplication() {
    return new PlayGround();
}
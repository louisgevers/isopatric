#ifndef ISOPATRIC_RENDER_VERTEXBUFFER_H
#define ISOPATRIC_RENDER_VERTEXBUFFER_H

namespace isopatric::render {

    enum class ShaderDataType {
        None = 0,
        Float, Float2, Float3, Float4,
        Int, Int2, Int3, Int4,
        Mat3, Mat4,
        Bool,
    };

    static int sizeOfShaderDataType(ShaderDataType type) {
        switch (type) {
            case ShaderDataType::None:
                return 0;
            case ShaderDataType::Float:
                return 4;
            case ShaderDataType::Float2:
                return 4 * 2;
            case ShaderDataType::Float3:
                return 4 * 3;
            case ShaderDataType::Float4:
                return 4 * 4;
            case ShaderDataType::Int:
                return 4;
            case ShaderDataType::Int2:
                return 4 * 2;
            case ShaderDataType::Int3:
                return 4 * 3;
            case ShaderDataType::Int4:
                return 4 * 4;
            case ShaderDataType::Mat3:
                return 4 * 3 * 3;
            case ShaderDataType::Mat4:
                return 4 * 4 * 4;
            case ShaderDataType::Bool:
                return 1;
        }
        ASSERT(false, "Unknown shader data type!")
        return 0;
    }

    struct VertexAttribute {
        ShaderDataType type;
        int size;
        int offset;
        bool normalized;

        VertexAttribute() = default;

        VertexAttribute(ShaderDataType shaderDataType, bool normalized = false)
                : type(shaderDataType), size(sizeOfShaderDataType(shaderDataType)), offset(0), normalized(normalized) {}

        int getComponentCount() const {
            switch (type) {
                case ShaderDataType::None:
                    return 0;
                case ShaderDataType::Float:
                case ShaderDataType::Int:
                case ShaderDataType::Bool:
                    return 1;
                case ShaderDataType::Float2:
                case ShaderDataType::Int2:
                    return 2;
                case ShaderDataType::Float3:
                case ShaderDataType::Int3:
                case ShaderDataType::Mat3:
                    return 3;
                case ShaderDataType::Float4:
                case ShaderDataType::Int4:
                case ShaderDataType::Mat4:
                    return 4;
            }
            ASSERT(false, "Unknown shader data type!")
            return 0;
        }
    };

    class VertexBufferLayout {
    public:
        VertexBufferLayout() { mStride = 0; };

        VertexBufferLayout(std::initializer_list<VertexAttribute> attributes)
                : mAttributes(attributes) {
            int offset = 0;
            mStride = 0;
            for (auto &attribute: mAttributes) {
                attribute.offset = offset;
                offset += attribute.size;
                mStride += attribute.size;
            }
        }

        const std::vector<VertexAttribute> &getAttributes() const { return mAttributes; };

        int getStride() const { return mStride; }

    private:
        std::vector<VertexAttribute> mAttributes;
        int mStride;
    };

    class VertexBuffer {
    public:
        virtual ~VertexBuffer() = default;

        virtual void bind() = 0;

        virtual void unbind() = 0;

        virtual void setLayout(VertexBufferLayout bufferLayout) = 0;

        virtual VertexBufferLayout &getLayout() = 0;

        static Scope<VertexBuffer> create(float *vertices, unsigned int size);
    };
}

#endif //ISOPATRIC_RENDER_VERTEXBUFFER_H

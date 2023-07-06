cmake_minimum_required(VERSION 3.16)
project(isopatric)

# Require C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Name of the IsoPatric executable
set(ISOPATRIC_EXE_NAME isopatric)
# Name of the IsoPatric library source code
set(ISOPATRIC_LIB_NAME libisopatric)

# --- SDL2 ---
find_package(SDL2 REQUIRED)
# --- GLAD ---
add_library(glad external/glad/src/glad.c)
target_include_directories(glad PRIVATE external/glad/include)
# --- IMGUI ---
set(EXTERNAL_IMGUI_SRC
        external/imgui/imconfig.h
        external/imgui/imgui.cpp
        external/imgui/imgui.h
        external/imgui/imgui_demo.cpp
        external/imgui/imgui_draw.cpp
        external/imgui/imgui_internal.h
        external/imgui/imgui_tables.cpp
        external/imgui/imgui_widgets.cpp
        external/imgui/imstb_rectpack.h
        external/imgui/imstb_textedit.h
        external/imgui/imstb_truetype.h
        external/imgui/backends/imgui_impl_opengl3.cpp
        external/imgui/backends/imgui_impl_opengl3.h
        external/imgui/backends/imgui_impl_sdl2.cpp
        external/imgui/backends/imgui_impl_sdl2.h
        )
add_library(imgui ${EXTERNAL_IMGUI_SRC})
target_link_libraries(imgui PRIVATE ${SDL2_LIBRARIES})
target_include_directories(imgui PRIVATE external/imgui ${SDL2_INCLUDE_DIR})
# --- STB_IMAGE ---
add_library(stb_image external/stb_image/stb_image.cpp)

# IsoPatric library source files
set(ISOPATRIC_LIB_SRC_CORE
        src/isopatric/isopatric.h
        src/isopatric/core/Application.cpp
        src/isopatric/core/Application.h
        src/isopatric/core/Assert.h
        src/isopatric/core/Base.h
        src/isopatric/core/Layer.h
        src/isopatric/core/LayerStack.cpp
        src/isopatric/core/LayerStack.h
        src/isopatric/core/Log.cpp
        src/isopatric/core/Log.h
        )

set(ISOPATRIC_LIB_SRC_EVENT
        src/isopatric/event/Event.h
        src/isopatric/event/EventQueue.h
        src/isopatric/event/sdl/EventQueue.cpp
        src/isopatric/event/sdl/EventQueue.h
        src/isopatric/event/KeyEvent.h
        src/isopatric/event/MouseEvent.h
        src/isopatric/event/WindowEvent.h
        )

set(ISOPATRIC_LIB_SRC_FILE
        src/isopatric/file/AssetReader.cpp
        src/isopatric/file/AssetReader.h
        )

set(ISOPATRIC_LIB_SRC_INPUT
        src/isopatric/input/Input.h
        src/isopatric/input/KeyCode.h
        src/isopatric/input/MouseCode.h
        src/isopatric/input/sdl/Input.cpp
        src/isopatric/input/sdl/Input.h
        )

set(ISOPATRIC_LIB_SRC_MATH
        src/isopatric/math/Matrix.cpp
        src/isopatric/math/Matrix.h
        src/isopatric/math/Vector.cpp
        src/isopatric/math/Vector.h
        )

set(ISOPATRIC_LIB_SRC_RENDER
        src/isopatric/render/IndexBuffer.h
        src/isopatric/render/RenderCommand.h
        src/isopatric/render/RenderContext.h
        src/isopatric/render/Renderer.cpp
        src/isopatric/render/Renderer.h
        src/isopatric/render/RendererAPI.h
        src/isopatric/render/Shader.h
        src/isopatric/render/Texture.h
        src/isopatric/render/VertexArray.h
        src/isopatric/render/VertexBuffer.h
        src/isopatric/render/opengl/IndexBuffer.cpp
        src/isopatric/render/opengl/IndexBuffer.h
        src/isopatric/render/opengl/RenderContext.cpp
        src/isopatric/render/opengl/RenderContext.h
        src/isopatric/render/opengl/RendererAPI.cpp
        src/isopatric/render/opengl/RendererAPI.h
        src/isopatric/render/opengl/Shader.cpp
        src/isopatric/render/opengl/Shader.h
        src/isopatric/render/opengl/Texture.cpp
        src/isopatric/render/opengl/Texture.h
        src/isopatric/render/opengl/VertexArray.cpp
        src/isopatric/render/opengl/VertexArray.h
        src/isopatric/render/opengl/VertexBuffer.cpp
        src/isopatric/render/opengl/VertexBuffer.h
        )

set(ISOPATRIC_LIB_SRC_UI
        src/isopatric/ui/UILayer.cpp
        src/isopatric/ui/UILayer.h
        )

set(ISOPATRIC_LIB_SRC_WINDOW
        src/isopatric/window/Window.h
        src/isopatric/window/sdl/Window.cpp
        src/isopatric/window/sdl/Window.h
        )

set(ISOPATRIC_LIB_SRC
        ${ISOPATRIC_LIB_SRC_CORE}
        ${ISOPATRIC_LIB_SRC_EVENT}
        ${ISOPATRIC_LIB_SRC_FILE}
        ${ISOPATRIC_LIB_SRC_INPUT}
        ${ISOPATRIC_LIB_SRC_MATH}
        ${ISOPATRIC_LIB_SRC_RENDER}
        ${ISOPATRIC_LIB_SRC_UI}
        ${ISOPATRIC_LIB_SRC_WINDOW}
        )

# Isopatric playground files
set(ISOPATRIC_PLAYGROUND_SRC
        src/playground/playground.cpp)

# Copy playground assets
file(COPY src/playground/assets DESTINATION ${CMAKE_BINARY_DIR})

# External includes for the library source files
set(ISOPATRIC_EXTERNAL_INCLUDES
        external/spdlog/include
        external/glad/include
        external/imgui
        external/stb_image
        external/glm
        ${SDL2_INCLUDE_DIRS})

# External libraries
set(ISOPATRIC_EXTERNAL_LIBRARIES ${SDL2_LIBRARIES} glad imgui stb_image)

# Include header files for all project
include_directories(src)

# Create the Isopatric library with its include dependencies
add_library(${ISOPATRIC_LIB_NAME} ${ISOPATRIC_LIB_SRC} ${ISOPATRIC_PLAYGROUND_SRC}) # TODO playground should be different lib
target_include_directories(${ISOPATRIC_LIB_NAME} PUBLIC ${ISOPATRIC_EXTERNAL_INCLUDES})
target_link_libraries(${ISOPATRIC_LIB_NAME} ${ISOPATRIC_EXTERNAL_LIBRARIES})

# Add the precompiled header
target_precompile_headers(${ISOPATRIC_LIB_NAME} PRIVATE src/isopatric/pch.h)

# Create the IsoPatric executable and link the library
add_executable(${ISOPATRIC_EXE_NAME} src/isopatric/isopatric.cpp)
target_link_libraries(${ISOPATRIC_EXE_NAME} ${ISOPATRIC_LIB_NAME})
target_precompile_headers(${ISOPATRIC_EXE_NAME} REUSE_FROM ${ISOPATRIC_LIB_NAME})
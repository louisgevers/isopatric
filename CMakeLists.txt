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

# IsoPatric library source files
set(ISOPATRIC_LIB_SRC
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
        src/isopatric/event/Event.h
        src/isopatric/event/EventQueue.h
        src/isopatric/event/sdl/EventQueue.cpp
        src/isopatric/event/sdl/EventQueue.h
        src/isopatric/event/KeyEvent.h
        src/isopatric/event/MouseEvent.h
        src/isopatric/event/WindowEvent.h
        src/isopatric/input/Input.h
        src/isopatric/input/KeyCode.h
        src/isopatric/input/MouseCode.h
        src/isopatric/input/sdl/Input.cpp
        src/isopatric/input/sdl/Input.h
        src/isopatric/render/IndexBuffer.h
        src/isopatric/render/RenderCommand.h
        src/isopatric/render/RenderContext.h
        src/isopatric/render/Renderer.cpp
        src/isopatric/render/Renderer.h
        src/isopatric/render/RendererAPI.h
        src/isopatric/render/Shader.h
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
        src/isopatric/render/opengl/VertexArray.cpp
        src/isopatric/render/opengl/VertexArray.h
        src/isopatric/render/opengl/VertexBuffer.cpp
        src/isopatric/render/opengl/VertexBuffer.h
        src/isopatric/ui/UILayer.cpp
        src/isopatric/ui/UILayer.h
        src/isopatric/window/Window.h
        src/isopatric/window/sdl/Window.cpp
        src/isopatric/window/sdl/Window.h
        )

# Isopatric playground files
set(ISOPATRIC_PLAYGROUND_SRC
        src/playground/playground.cpp)

# External includes for the library source files
set(ISOPATRIC_EXTERNAL_INCLUDES
        external/spdlog/include
        external/glad/include
        external/imgui
        ${SDL2_INCLUDE_DIRS})

# External libraries
set(ISOPATRIC_EXTERNAL_LIBRARIES ${SDL2_LIBRARIES} glad imgui)

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
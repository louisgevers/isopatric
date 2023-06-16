cmake_minimum_required(VERSION 3.15)
project(isopatric)

# Require C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Name of the IsoPatric executable
set(ISOPATRIC_EXE_NAME isopatric)
# Name of the IsoPatric library source code
set(ISOPATRIC_LIB_NAME libisopatric)

# --- SDL2 ---
find_package(SDL2 REQUIRED)

# IsoPatric library source files
set(ISOPATRIC_LIB_SRC 
        src/isopatric/core/Application.cpp
        src/isopatric/core/Application.h
        src/isopatric/core/Assert.h
        src/isopatric/core/Base.h
        src/isopatric/core/Log.cpp
        src/isopatric/core/Log.h
        src/isopatric/event/Event.h
        src/isopatric/event/KeyEvent.h
        src/isopatric/event/MouseEvent.h
        src/isopatric/event/WindowEvent.h
        src/isopatric/window/Window.h
        src/isopatric/window/sdl/Window.cpp
        src/isopatric/window/sdl/Window.h
    )

# External includes for the library source files
set(ISOPATRIC_EXTERNAL_INCLUDES 
        external/spdlog/include
        ${SDL2_INCLUDE_DIRS})

# External libraries
set(ISOPATRIC_EXTERNAL_LIBRARIES ${SDL2_LIBRARIES})

# Include header files for all project
include_directories(src)

# Create the IsoPatric library with its include dependencies
add_library(${ISOPATRIC_LIB_NAME} ${ISOPATRIC_LIB_SRC})
target_include_directories(${ISOPATRIC_LIB_NAME} PUBLIC ${ISOPATRIC_EXTERNAL_INCLUDES})
target_link_libraries(${ISOPATRIC_LIB_NAME} ${ISOPATRIC_EXTERNAL_LIBRARIES})

# Add the precompiled header
target_precompile_headers(${ISOPATRIC_LIB_NAME} PRIVATE src/isopatric/pch.h)

# Create the IsoPatric executable and link the library
add_executable(${ISOPATRIC_EXE_NAME} src/isopatric/isopatric.cpp)
target_link_libraries(${ISOPATRIC_EXE_NAME} ${ISOPATRIC_LIB_NAME})
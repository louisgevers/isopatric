cmake_minimum_required(VERSION 3.25)
project(isopatric)

set(CMAKE_CXX_STANDARD 17)

# IsoPatric library sources
set(ISOPATRIC_LIB_NAME isopatriclib)
set(ISOPATRIC_LIB_SRC
        src/isopatric/window/window.h
        src/isopatric/window/window.cpp)

# Executables
add_executable(${PROJECT_NAME} src/isopatric/isopatric.cpp)

# Add the IsoPatric library
include_directories(src)
add_library(${ISOPATRIC_LIB_NAME} ${ISOPATRIC_LIB_SRC})
target_link_libraries(${PROJECT_NAME} PRIVATE ${ISOPATRIC_LIB_NAME})
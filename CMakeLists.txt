cmake_minimum_required(VERSION 3.10)
project(physim)

set(CMAKE_CXX_STANDARD 17)

# Output binary to app/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../app/bin)

# Find OpenGL
find_package(OpenGL REQUIRED)

# GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

# GLM
find_package(glm REQUIRED)

include_directories(
    ${OPENGL_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
    include
)

link_directories(${GLFW_LIBRARY_DIRS})

add_executable(physim src/main.cpp)

target_link_libraries(physim
    ${OPENGL_gl_LIBRARY}
    ${GLFW_LIBRARIES}
    ${CMAKE_DL_LIBS}
)

# Install target
install(TARGETS physim DESTINATION ../app/bin)

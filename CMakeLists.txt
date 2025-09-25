cmake_minimum_required(VERSION 3.10)
project(physim VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../app/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../app/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../app/lib)

# Global package finding - shared across all subdirectories
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
find_package(glm REQUIRED)

# Global include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OPENGL_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
)

# Global link directories
link_directories(${GLFW_LIBRARY_DIRS})

# Add subdirectories
add_subdirectory(src)

# Future subdirectories
# add_subdirectory(lib)      # For physics engine library
# add_subdirectory(tests)    # For unit tests
# add_subdirectory(examples) # For example simulations

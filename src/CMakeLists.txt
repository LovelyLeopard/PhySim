# Source files for the main PhySim executable
set(PHYSIM_SOURCES
    main.cpp
    glad.c  # GLAD OpenGL loader
    # Future source files will be added here:
    # physics/pendulum.cpp
    # physics/projectile.cpp
    # renderer/window.cpp
    # ui/interface.cpp
)

# Create the main executable
add_executable(physim ${PHYSIM_SOURCES})

# Link libraries to the executable
target_link_libraries(physim
    ${OPENGL_gl_LIBRARY}
    ${GLFW_LIBRARIES}
    ${CMAKE_DL_LIBS}
    glog::glog
)

# Set properties for the executable
set_target_properties(physim PROPERTIES
    OUTPUT_NAME "physim"
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../app/bin
)

# Install target
install(TARGETS physim
    RUNTIME DESTINATION ../app/bin
    COMPONENT Runtime
)

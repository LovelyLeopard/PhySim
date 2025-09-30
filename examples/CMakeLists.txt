file(GLOB EXAMPLE_SOURCES "*.cpp")

# Create executables for each example
foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    # Get filename without path and extension
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    
    # Create executable
    add_executable(${EXAMPLE_NAME} 
        ${EXAMPLE_SOURCE}
        ../src/glad.c  # Include GLAD source for all examples
    )
    
    # Link libraries
    target_link_libraries(${EXAMPLE_NAME}
        ${OPENGL_gl_LIBRARY}
        ${GLFW_LIBRARIES}
        ${CMAKE_DL_LIBS}
        glog::glog
    )
    
    # Set properties
    set_target_properties(${EXAMPLE_NAME} PROPERTIES
        OUTPUT_NAME "${EXAMPLE_NAME}"
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../app/bin
    )
    
    # Install target
    install(TARGETS ${EXAMPLE_NAME}
        RUNTIME DESTINATION ../app/bin
        COMPONENT Runtime
    )
endforeach()
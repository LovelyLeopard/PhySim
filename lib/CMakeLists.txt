# PhySim Physics Engine Library
# This will contain the core physics simulation components

# Future library sources (currently empty - will be populated as development goes on)
set(PHYSIM_LIB_SOURCES
    # physics/core/world.cpp
    # physics/core/object.cpp
    # physics/simulations/pendulum.cpp
    # physics/simulations/projectile.cpp
    # physics/simulations/gravity.cpp
    # physics/math/vector.cpp
    # physics/math/matrix.cpp
    # renderer/graphics.cpp
    # renderer/shader.cpp
)

# add_library(physim_engine STATIC ${PHYSIM_LIB_SOURCES})

# target_include_directories(physim_engine PUBLIC 
#     ${CMAKE_CURRENT_SOURCE_DIR}
#     ${CMAKE_SOURCE_DIR}/include
# )

# target_link_libraries(physim_engine
#     ${OPENGL_gl_LIBRARY}
#     ${GLFW_LIBRARIES}
#     ${CMAKE_DL_LIBS}
# )

# Install library
# install(TARGETS physim_engine
#     ARCHIVE DESTINATION ../app/lib
#     LIBRARY DESTINATION ../app/lib
#     COMPONENT Development
# )
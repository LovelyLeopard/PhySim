#include <GLFW/glfw3.h>
#include <iostream>
#include <glog/logging.h>

int main() {
    // Initialize Google Logging
    google::InitGoogleLogging("physim");
    
    // GLFW INIT
    if(!glfwInit()) {
        LOG(ERROR) << "Failed to initialize GLFW";
        return -1;
    }

    // CREATE WINDOW
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
    if(!window) {
        LOG(ERROR) << "Failed to create GLFW window";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    while(!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

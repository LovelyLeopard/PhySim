#include <glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
#include <glog/logging.h>

// Application constants
const int NUM_SEGMENTS = 36; // 36 points with 10 degrees separation
const float RADIUS = 0.5f;   // Circle Radius
const float PI = 3.14159265358979323846f;
const int UPDATE_INTERVAL_MS = 15; // ~66.67 FPS

// OpenGL resources
unsigned int VBO, VAO, shaderProgram;

// Screen state management
struct DisplayState
{
    int currentWidth = 0;
    int currentHeight = 0;
    float aspectRatio = 1.0f;
    bool requiresUpdate = true;
};

DisplayState screenState;
auto lastUpdateTime = std::chrono::steady_clock::now();

// Geometry generation
std::vector<float> generateCircleVertices(float aspectCorrection)
{
    std::vector<float> vertexData; // Array to store vertex positions
    for (int i = 0; i < NUM_SEGMENTS; ++i)
    {
        float angle = 2.0f * PI * float(i) / float(NUM_SEGMENTS);
        float x = RADIUS * std::cos(angle);
        float y = RADIUS * std::sin(angle);

        // Aspect Ratio correction
        if (aspectCorrection > 1.0f)
        {
            x /= aspectCorrection;
        }
        else
        {
            y *= aspectCorrection;
        }
        vertexData.push_back(x);
        vertexData.push_back(y);
        vertexData.push_back(0.0f); // Z coordinate is always 0 for 2D shapes
    }
    return vertexData;
}

// Rendering functions
void renderCircle()
{
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_LOOP, 0, NUM_SEGMENTS);
}

void renderFrame()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    renderCircle(); // Call draw function

    // Can also include other similar draw or render functions here
}

// Screen management
bool detectScreenResize(GLFWwindow *window)
{
    int newWidth, newHeight;
    glfwGetFramebufferSize(window, &newWidth, &newHeight);

    if (newWidth != screenState.currentWidth || newHeight != screenState.currentHeight)
    {
        screenState.currentWidth = newWidth;
        screenState.currentHeight = newHeight;
        screenState.aspectRatio = static_cast<float>(newWidth) / static_cast<float>(newHeight);
        screenState.requiresUpdate = true;
        glViewport(0, 0, newWidth, newHeight);
        return true;
    }
    return false;
}

void refreshGeometry()
{
    if (screenState.requiresUpdate)
    {
        auto vertexData = generateCircleVertices(screenState.aspectRatio);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER,
                     vertexData.size() * sizeof(float),
                     vertexData.data(),
                     GL_STATIC_DRAW);

        screenState.requiresUpdate = false;
    }
}

// Main update system
void updateSystem(GLFWwindow *window)
{
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
                       currentTime - lastUpdateTime)
                       .count();

    if (elapsed >= UPDATE_INTERVAL_MS)
    {
        // Check for screen changes
        detectScreenResize(window);

        // Update graphics data if needed
        refreshGeometry();

        lastUpdateTime = currentTime;
    }
}

// Shader initialization
void setupShaders()
{
    const char *vertexCode = "#version 330 core\n"
                             "layout (location = 0) in vec3 aPos;\n"
                             "void main() {\n"
                             "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                             "}\0";

    const char *fragmentCode = "#version 330 core\n"
                               "out vec4 FragColor;\n"
                               "void main() {\n"
                               "   FragColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);\n"
                               "}\0";

    // Compile and link shaders
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexCode, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentCode, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

int main()
{
    // Initialize Google Logging
    google::InitGoogleLogging("drawCircle");

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "GLAD Circle", nullptr, nullptr);
    if (!window)
    {
        LOG(ERROR) << "Failed to create GLFW window";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        LOG(ERROR) << "Failed to initialize GLAD";
        glfwTerminate();
        return -1;
    }

    // Initialize systems
    setupShaders();

    // Setup buffers
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Force initial update
    detectScreenResize(window);

    // Main application loop
    while (!glfwWindowShouldClose(window))
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        // Update all systems
        updateSystem(window);

        // Render everything
        renderFrame();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    glfwTerminate();
    return 0;
}
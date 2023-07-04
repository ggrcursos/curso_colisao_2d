// #include <glad/glad.h>
// #include <GLFW/glfw3.h>

// #include <iostream>
// #include <string>
// #include <iostream>
// #include <sstream>
// #include <fstream>
#include <memory>
#include <iostream>
#include "renders/graphIo.hpp"
#include "renders/opengl/glfwGlad/glfwGlad.hpp"
#include "renders/keysInfo.hpp"

int main()
{
    std::unique_ptr<Renders::GraphIO> renderIO_ptr = std::make_unique<Renders::OpenGl::GlfwGlad>();
    renderIO_ptr->initialize();
    renderIO_ptr->setShadersPath({"file1", "file2"});
    renderIO_ptr->createWindow(0, 0, 800, 500, "Hello World!");
    renderIO_ptr->registerInputHandlerCb([&](Renders::Key key)
                                         {
    std::cout << key << std::endl;
    if(key == Renders::Key::ESCAPE)
    {
        renderIO_ptr->closeWindow();
    } });

    while (!renderIO_ptr->keepRunning())
    {
        // 1 - clearScreen
        renderIO_ptr->clearWindow();

        // 3 - Update

        // 2 - Draw

        // 3 - input
        renderIO_ptr->inputHandler();
        // 4 -
        renderIO_ptr->doubleBuffer();
        renderIO_ptr->handleIOEvents();
    }

    renderIO_ptr->shutDown();
    return 0;
}

#if 0
 // settings
unsigned int scrWidth = 800;
unsigned int scrHeight = 600;
const char* title = "Pong";
GLuint shaderProgram;
 

/*
    main loop methods
*/

// initialize GLFW
void initGLFW(unsigned int versionMajor, unsigned int versionMinor) {
    glfwInit();

    // pass in window params
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, versionMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, versionMinor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // macos specific parameter
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

// create window
void createWindow(GLFWwindow*& window, 
    const char* title, unsigned int width, unsigned int height, 
    GLFWframebuffersizefun framebufferSizeCallback) {
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        return;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
}


/*
    shader methods
*/

// read file
std::string readFile(const char* filename) {
    std::ifstream file;
    std::stringstream buf;

    std::string ret = "";

    // open file
    file.open(filename);

    if (file.is_open()) {
        // read buffer
        buf << file.rdbuf();
        ret = buf.str();
    }
    else {
        std::cout << "Could not open " << filename << std::endl;
    }

    // close file
    file.close();

    return ret;
}

// generate shader
int genShader(const char* filepath, GLenum type) {
    std::string shaderSrc = readFile(filepath);
    const GLchar* shader = shaderSrc.c_str();

    // build and compile shader
    int shaderObj = glCreateShader(type);
    glShaderSource(shaderObj, 1, &shader, NULL);
    glCompileShader(shaderObj);

    // check for errors
    int success;
    char infoLog[512];
    glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shaderObj, 512, NULL, infoLog);
        std::cout << "Error in shader compilation: " << infoLog << std::endl;
        return -1;
    }

    return shaderObj;
}

// generate shader program
int genShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath) {
    int shaderProgram = glCreateProgram();

    // compile shaders
    int vertexShader = genShader(vertexShaderPath, GL_VERTEX_SHADER);
    int fragmentShader = genShader(fragmentShaderPath, GL_FRAGMENT_SHADER);

    if (vertexShader == -1 || fragmentShader == -1) {
        return -1;
    }

    // link shaders
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // check for errors
    int success;
    char infoLog[512];
    glGetShaderiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "Error in shader linking: " << infoLog << std::endl;
        return -1;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

// bind shader
void bindShader(int shaderProgram) {
    glUseProgram(shaderProgram);
}

// set projection
void setOrthographicProjection(int shaderProgram,
    float left, float right,
    float bottom, float top,
    float near, float far) {
    float mat[4][4] = {
        { 2.0f / (right - left), 0.0f, 0.0f, 0.0f },
        { 0.0f, 2.0f / (top - bottom), 0.0f, 0.0f },
        { 0.0f, 0.0f, -2.0f / (far - near), 0.0f },
        { -(right + left) / (right - left), -(top + bottom) / (top - bottom), -(far + near) / (far - near), 1.0f }
    };

    bindShader(shaderProgram);
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, &mat[0][0]);
}

// load GLAD library
bool loadGlad() {
    return gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

// callback for window size change
void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    scrWidth = width;
    scrHeight = height;

    // update projection matrix
    setOrthographicProjection(shaderProgram, 0, width, 0, height, 0.0f, 1.0f);
 
}

// process input
void processInput(GLFWwindow* window, double dt) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    } 
}

// clear screen
void clearScreen() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

// new frame
void newFrame(GLFWwindow* window) {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

 // delete shader
void deleteShader(int shaderProgram) {
    glDeleteProgram(shaderProgram);
}

/*
    cleanup methods
*/

// terminate glfw
void cleanup() {
    glfwTerminate();
}

int main() {
    std::cout << "Hello, Atari!" << std::endl;

    // timing
    double dt = 0.0;
    double lastFrame = 0.0;

    // initialization
    initGLFW(3, 3);

    // create window
    GLFWwindow* window = nullptr;
    createWindow(window, title, scrWidth, scrHeight, framebufferSizeCallback);
    if (!window) {
        std::cout << "Could not create window" << std::endl;
        cleanup();
        return -1;
    }

    // load glad
    if (!loadGlad()) {
        std::cout << "Could not init GLAD" << std::endl;
        cleanup();
        return -1;
    }

    glViewport(0, 0, scrWidth, scrHeight);

    // shaders
    shaderProgram = genShaderProgram("assets/shaders/main.vs", "assets/shaders/main.fs");
    setOrthographicProjection(shaderProgram, 0, scrWidth, 0, scrHeight, 0.0f, 1.0f);

    /*
        Paddle VAO/BOs
    */

    // setup vertex data
    float paddleVertices[] = {
        //	x		y
         0.5f,  0.5f,
        -0.5f,  0.5f,
        -0.5f, -0.5f,
         0.5f, -0.5f
    };

    // setup index data
    unsigned int paddleIndices[] = {
        0, 1, 2, // top left triangle
        2, 3, 0  // bottom right triangle
    };
 

    // render loop
    while (!glfwWindowShouldClose(window)) {
        // update time
        dt = glfwGetTime() - lastFrame;
        lastFrame += dt;

        /*
            physics
        */

        // input
        processInput(window, dt);
 

        /*
            graphics
        */
         
        // swap frames
        newFrame(window);
    }

 
    deleteShader(shaderProgram);
    cleanup();

    return 0;
}
#endif
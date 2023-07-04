#include "glfwGlad.hpp"
#include "utils/Log.hpp"

using namespace Render::Utils;
namespace Renders
{
    namespace OpenGl
    {

        GlfwGlad::GlfwGlad() : GraphIO()
        {
            Log(INFO) << "Create render Opengl using Glfw with Glad!" << Log::endl();
        }
        void GlfwGlad::initialize()
        {

            glfwInit();
            // pass in window params
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, VERSION_MAJOR);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, VERSION_MINOR);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            // macos specific parameter
#ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
        }
        void GlfwGlad::createWindow(float posX, float posY, short width, short height, const std::string &title)
        {
            m_posX = posX;
            m_posY = posY;
            m_width = width;
            m_height = height;
            m_title = title;

            m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
            if (!m_window)
            {
                return;
            }
            glfwMakeContextCurrent(m_window);

            // define callbacks internal
            glfwSetWindowUserPointer(m_window, this);
            auto reshapeFunc = [](GLFWwindow *window, int w, int h)
            {
                static_cast<GlfwGlad *>(glfwGetWindowUserPointer(window))->framebufferSizeCallback(window, w, h);
            };
            // glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);
            glfwSetFramebufferSizeCallback(m_window, reshapeFunc);

            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                Log(ERROR) << "Problems width  Opengl Loader " << Log::endl();
                exit(0);
            }
        }
        void GlfwGlad::registerInputHandlerCb(std::function<void(Key k)> cb)
        {
            m_inputHandlerCb = cb;
        }
        void GlfwGlad::clearWindow()
        {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
        }
        void GlfwGlad::inputHandler()
        {
            Key current_presed_key = UNKNOWN;
            if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            {
                current_presed_key = Key::ESCAPE;
            }
            m_inputHandlerCb(current_presed_key);
        }
        void GlfwGlad::doubleBuffer()
        {
            glfwSwapBuffers(m_window);
        }
        void GlfwGlad::handleIOEvents()
        {
            glfwPollEvents();
        }

        void GlfwGlad::closeWindow()
        {
              glfwSetWindowShouldClose(m_window, true);
        }
        void GlfwGlad::shutDown()
        {
            glfwTerminate();
        }

        bool GlfwGlad::keepRunning()
        {
            return glfwWindowShouldClose(m_window);
        }
        void GlfwGlad::framebufferSizeCallback(GLFWwindow *window, int width, int height)
        {
            glViewport(0, 0, width, height);
            m_width = width;
            m_height = height;

            // update projection matrix
            setOrthographicProjection(m_shaderProgram, 0, width, 0, height, 0.0f, 1.0f);
        }
        // set projection
        void GlfwGlad::setOrthographicProjection(int shaderProgram,
                                                 float left, float right,
                                                 float bottom, float top,
                                                 float near, float far)
        {
            float mat[4][4] = {
                {2.0f / (right - left), 0.0f, 0.0f, 0.0f},
                {0.0f, 2.0f / (top - bottom), 0.0f, 0.0f},
                {0.0f, 0.0f, -2.0f / (far - near), 0.0f},
                {-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(far + near) / (far - near), 1.0f}};

            glUseProgram(shaderProgram);
            glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, &mat[0][0]);
        }

    }
}
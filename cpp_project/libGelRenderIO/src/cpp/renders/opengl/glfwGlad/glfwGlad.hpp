#ifndef GLFWGLAD_HPP
#define GLFWGLAD_HPP
#include "../../graphIo.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../../keysInfo.hpp"
#define VERSION_MAJOR 3
#define VERSION_MINOR 3

namespace Renders
{
    namespace OpenGl
    {

        class GlfwGlad : public GraphIO
        {
        public:
            GlfwGlad();
            virtual ~GlfwGlad() {}
            virtual void initialize();
            virtual void createWindow(float posX, float posY, short width, short height, const std::string &title);
            virtual void registerInputHandlerCb(std::function<void(Key k)>);
            virtual void clearWindow();
            virtual void inputHandler();
            virtual void doubleBuffer();
            virtual void closeWindow();
            virtual void handleIOEvents();
            virtual void shutDown();
            virtual bool keepRunning() ;

        private:
            void setOrthographicProjection(int shaderProgram, float left, float right, float bottom, float top, float near, float far);
            void framebufferSizeCallback(GLFWwindow* window, int width, int height) ;
            
            GLFWwindow *m_window;
            GLuint m_shaderProgram;
        };
    }
}
#endif
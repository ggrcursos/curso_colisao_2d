#ifndef GRAPHIO_HPP
#define GRAPHIO_HPP
#include <string>
#include <functional>
#include<vector>
#include "keysInfo.hpp"
namespace Renders
{
    class GraphIO
    {
    public:
        GraphIO(): m_posX(0),
                               m_posY(0),
                               m_width(0),
                               m_height(0),
                               m_title("")
        {
        }

        virtual ~GraphIO(){}
        virtual void initialize() = 0;
        virtual void createWindow(float posX, float posY, short width, short height, const std::string &title) = 0;
        virtual void registerInputHandlerCb(std::function<void(Key k)>) = 0;

        virtual void clearWindow() = 0;
        virtual void inputHandler() = 0;
        virtual void doubleBuffer() = 0;
        virtual void handleIOEvents() = 0;
        virtual void closeWindow() = 0;
        virtual void shutDown() = 0;
        void setShadersPath(std::vector<std::string> listPaths)
        {
            m_listPaths = listPaths;
        }

        virtual bool keepRunning() = 0;

    protected: 
        std::function<void(Key k)> m_inputHandlerCb;
        float m_posX;
        float m_posY;
        short m_width;
        short m_height;
        std::vector<std::string> m_listPaths;
        std::string m_title;
    };
}
#endif
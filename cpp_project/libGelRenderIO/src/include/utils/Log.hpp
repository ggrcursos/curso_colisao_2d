#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <ostream>
#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
using namespace std;
namespace Render
{
    namespace Utils
    {
        enum ETypeLog
        {
            DEBUG,
            INFO,
            WARN,
            ERROR,
            UNKOWN
        };

        class Log
        {
        public:

            std::string getTimeStr()
            { 
                auto l_now = std::chrono::system_clock::now();
                auto l_localTime = std::chrono::system_clock::to_time_t(l_now);
                std::stringstream l_ss;
                l_ss << std::put_time(std::localtime(&l_localTime), "%F %H-%M-%S");
                return l_ss.str();
            }
            
            Log(ETypeLog type = ETypeLog::UNKOWN)
            {
                m_msglevel = type;

                if (type != ETypeLog::UNKOWN)
                {
                    operator<<(getTimeStr()) << (" [" + getLabel(type) + "] ");
                }
            }
            virtual ~Log()
            {
            }

            static std::string endl()
            {
                return "\n";
            }

            template <class T>
            Log &operator<<(const T &msg)
            {

                std::cout << msg;
                return *this;
            }

        private:
            ETypeLog m_msglevel;
            inline string getLabel(ETypeLog e_type)
            {
                string l_label;
                switch (e_type)
                {
                case DEBUG:
                    l_label = "DEBUG";
                    break;
                case INFO:
                    l_label = "INFO";
                    break;
                case WARN:
                    l_label = "WARN";
                    break;
                case ERROR:
                    l_label = "ERROR";
                    break;
                default:
                    l_label = "";
                    break;
                }
                return l_label;
            }
        };
    }
}
#endif
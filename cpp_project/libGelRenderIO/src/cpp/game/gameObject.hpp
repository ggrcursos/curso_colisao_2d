#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include "MathUtils.h"
#include<string>

namespace pingPong
{
    class GameObject
    {
        public:
        GameObject(const std::string& id): m_id(id), m_position(Vec2{0.0f,0.0f}){}
        virtual void update(float timeStamp) = 0;
        virtual void draw() = 0;
        virtual std::string getId() = 0;

        protected:
        std::string m_id;
        Vec2 m_position;


    };  
}
#endif
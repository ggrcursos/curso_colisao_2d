#ifndef BALL_HPP
#define BALL_HPP
#include "gameObject.hpp"
#include <string>

namespace pingPong
{
    class Ball : public GameObject
    {
    public:
        Ball(const std::string &id, const Vec2 &startPosition, float radius) ;
        virtual void update(float timeStamp);
        virtual void draw();
        virtual std::string getId();
    protected:
    float m_radius;

    };
}

#endif
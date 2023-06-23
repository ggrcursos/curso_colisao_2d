#ifndef RECT_HPP
#define RECT_HPP

#include <iostream>
#include "Math.hpp"
#include "IShape.hpp"

using namespace Engine;
namespace Render
{
    namespace Shape
    {
        class Rect : public IShape
        {
        public:

            Rect(const Vec2 &startPosition, const Vec2 &velocity, const Vec2 &size, unsigned int color, float rotation = 0.0f);
            virtual void render();
            virtual void update(float deltaTime);
            virtual Vec2 getPosition();

        protected:
            Vec2 m_position;
            Vec2 m_velocity;
            Vec2 m_size;
            unsigned int m_color;
            float m_rotation;
        };
    }
}
#endif

#include <iostream>
#include "shapes/Rect.hpp"
#include "utils/Log.hpp" 

namespace Render
{
    namespace Shape
    {
        Rect::Rect(const Vec2 &startPosition, const Vec2 &velocity, const Vec2 &size, unsigned int color, float rotation) : m_position(startPosition),
                                                                                                                                m_velocity(velocity),
                                                                                                                                m_size(size),
                                                                                                                                m_color(color),
                                                                                                                                m_rotation(rotation) 
        {
                Utils::Log(Utils::INFO)<<  "Shape Created" << Utils::Log::endl();
        }
        void Rect::render()
        {
        }

    
        
        void Rect::update(float deltaTime)
        {
            m_position += m_velocity;
        }
        Vec2 Rect::getPosition()
        {
            return m_position;
        }
    }
}

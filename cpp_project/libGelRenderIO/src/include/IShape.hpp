#ifndef IGRAPH_HPP
#define IGRAPH_HPP

#include <iostream>
#include "Math.hpp"

using namespace Engine;
namespace Render
{
    class IShape
    {
    public:
        /***
         * Esta function deve ser implementada nas classes filhas
         */
        virtual void render() = 0;
        virtual void update(float deltaTime) = 0;
        virtual Vec2 getPosition() = 0;
        virtual  ~IShape(){}
    };
}
#endif
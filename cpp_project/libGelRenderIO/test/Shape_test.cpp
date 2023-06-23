#include "Math.hpp"
#include "IShape.hpp"
#include "shapes/Rect.hpp"
#include <memory>
#include <gtest/gtest.h>

using namespace Engine;
using namespace Render;

bool operator==(const Vec2 &v1, const Vec2 &v2)
{
    return (v1.x == v2.x && v1.y == v2.y);
}

TEST(RectTest, TestUpdate)
{
    Vec2 startPosition(1.0f , 2.0f);
    Vec2 velocity(0.0f, 5.0f);
    Vec2 size(2.0f, 2.0f);
    unsigned int color = 0xffffff;
    std::unique_ptr<IShape> newShapePtr = std::make_unique<Shape::Rect>(startPosition, velocity, size,color);

    const float deltaTime = 30.0f;
    const float maxIterations = 10;
    for(size_t i = 0; i < maxIterations; i++)
    {
        newShapePtr->update(deltaTime);
    }
    
    Vec2 finalPositionExpected(1.0f,  52.0f);
    ASSERT_TRUE(newShapePtr->getPosition() == finalPositionExpected);
}

#include "Math.hpp"
#include <gtest/gtest.h>
using namespace Engine;

bool operator ==(const Vec2& v1, const Vec2& v2)
{
    return (v1.x == v2.x && v1.y == v2.y);
}
TEST(Vec2Test , TestSumVec2D)
{
    Vec2 v1 = Vec2{1.0f, 2.0f};
    Vec2 v2 = Vec2{2.0f, 3.0f};
    Vec2 sum = v1 + v2;
    Vec2 expected{ 3.0f, 5.0f};
    ASSERT_TRUE(sum ==  expected);
}
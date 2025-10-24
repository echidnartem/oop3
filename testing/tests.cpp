#include <gtest/gtest.h>
#include "../include/pentagon.h"
#include "../include/hexagon.h"
#include "../include/octagon.h"


TEST(test_01, pentagon_area)
{
    Pentagon p({{0, 0}, {2, 0}, {3, 2}, {1, 3}, {-1, 2}});
    double area = static_cast<double>(p);
    ASSERT_NEAR(area, 8.0, 0.5);
}

TEST(test_02, hexagon_center)
{
    Hexagon h({{3, 1}, {2, 2.732}, {0, 2.732}, {-1, 1}, {0, -0.732}, {2, -0.732}});
    Point c = h.centre_figure();
    ASSERT_NEAR(c.x, 1.0, 0.5);
    ASSERT_NEAR(c.y, 1.0, 0.5);
}

TEST(test_03, octagon_equal)
{
    std::vector<Point> pts = {{0,0}, {1,0}, {2,1}, {2,2}, {1,3}, {0,3}, {-1,2}, {-1,1}};
    Octagon a(pts);
    Octagon b(pts);
    ASSERT_TRUE(a == b);
}

TEST(test_04, octagon_not_equal)
{
    Octagon a({{0,0}, {1,0}, {2,1}, {2,2}, {1,3}, {0,3}, {-1,2}, {-1,1}});
    Octagon b({{0,0}, {2,0}, {3,1}, {3,2}, {2,3}, {0,3}, {-1,2}, {-1,1}});
    ASSERT_FALSE(a == b);
}

TEST(test_05, hexagon_move)
{
    std::vector<Point> pts(6, {1,1});
    Hexagon a(pts);
    Hexagon b;
    Hexagon c;
    c = a;
    b = std::move(a);
    ASSERT_TRUE(b == c);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
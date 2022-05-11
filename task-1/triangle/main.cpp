#include "triangle.h"

void test(const triangle& t1, const triangle& t2)
{
    if (isColliding(t1, t2) == true)
        std::cout << "Triangles are colliding\n";
    else
        std::cout << "Triangles aren't colliding\n";
    std::cout << "=============================\n";
}

int main()
{
    triangle t1, t2;

    t1 = {vec2{-5, 1}, vec2{-2, -2}, vec2{3, 5}};
    t2 = {vec2{0, -2}, vec2{3, 0}, vec2{0, 6}};
    test(t1, t2);

    t1 = {vec2{-2.5, 4}, vec2{-2, -2}, vec2{0.5, 2}};
    t2 = {vec2{0, -1}, vec2{2.5, 0}, vec2{-1, 6}};
    test(t1, t2);

    t1 = {vec2{-3, 0}, vec2{-1, -1}, vec2{3, 3}};
    t2 = {vec2{-3, -2}, vec2{1, -2}, vec2{-5, 1}};
    test(t1, t2);

    t1 = {vec2{-1, 1}, vec2{1, 0}, vec2{0, 3}};
    t2 = {vec2{0, 3}, vec2{-2, 5}, vec2{-1, 5}};
    test(t1, t2);

    t1 = {vec2{-5, 1}, vec2{-2, -2}, vec2{-1, 2}};
    t2 = {vec2{0, -2}, vec2{3, 0}, vec2{0, 6}};
    test(t1, t2);

}
#pragma once

#include <iostream>
#include <array>

struct vec2
{
    float x, y;
};

struct segment
{
    segment(vec2 first, vec2 second);
    
    float A, B, C;
    vec2 p, q;
};

struct triangle
{
    std::array<vec2, 3> points;
};

enum positions { OVER, ON, UNDER };

positions pointPosition(const vec2& referencePoint, const segment& line);
bool isPointInside(const vec2& point, const triangle& t);
bool isLinesIntersecting(const segment& first, const segment& second);
bool isColliding(const triangle& triangle1, const triangle& triangle2);
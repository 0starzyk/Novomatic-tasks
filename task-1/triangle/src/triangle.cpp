#include "triangle.h"

segment::segment(vec2 first, vec2 second)
{
    p = first;
    q = second;
    if (p.x == q.x)
    {
        A = 1;
        B = 0;
        C = -p.x;
    }
    else
    {
        A = (p.y - q.y) / (p.x - q.x);
        B = -1;
        C = p.y - A * p.x;
    }
}

positions pointPosition(const vec2& referencePoint, const segment& line)
{
    if (line.p.x == line.q.x)
    {
        if (referencePoint.x > line.p.x)
            return OVER;
        else if (referencePoint.x == line.p.x)
            return ON;
        else
            return UNDER;
    }

    else
    {
        float a = (line.p.y - line.q.y) / (line.p.x - line.q.x);
        float b = line.p.y - a * line.p.x;
        float y = a * referencePoint.x + b;

        if (y > referencePoint.y)
            return OVER;
        else if (y == referencePoint.y)
            return ON;
        else
            return UNDER;
    }
}

bool isPointInside(const vec2& point, const triangle& t)
{
    std::array<segment, 3> lines = {
        segment(t.points[0], t.points[1]),
        segment(t.points[1], t.points[2]),
        segment(t.points[0], t.points[2])
    };

    for (int i = 0; i < 3; i++)
    {
        if (pointPosition(point, lines[i]) == ON && point.x <= std::max(lines[i].p.x, lines[i].q.x) && point.x >= std::min(lines[i].p.x, lines[i].q.x))
            return true;

        int k = i + 2 > 2 ? 0 : i + 2;
        if (pointPosition(point, lines[i]) != pointPosition(t.points[k], lines[i]))
            return false;
    }

    return true;
}

bool isLinesIntersecting(const segment& first, const segment& second)
{

    if (second.A * first.B - first.A * second.B == 0)
        return false;

    float y0 = (first.A * second.C - second.A * first.C) / (second.A * first.B - first.A * second.B);

    if (y0 <= std::max(first.p.y, first.q.y) && y0 >= std::min(first.p.y, first.q.y) && y0 <= std::max(second.p.y, second.q.y) && y0 >= std::min(second.p.y, second.q.y))
        return true;

    return false;
}


bool isColliding(const triangle& triangle1, const triangle& triangle2)
{
    // First triangle segments
    std::array<segment, 3> firstSegments = {
        segment(triangle1.points[0], triangle1.points[1]),
        segment(triangle1.points[1], triangle1.points[2]),
        segment(triangle1.points[0], triangle1.points[2])
    };
    
    // Second triangle segments
    std::array<segment, 3> secondSegments = {
        segment(triangle2.points[0], triangle2.points[1]),
        segment(triangle2.points[1], triangle2.points[2]),
        segment(triangle2.points[0], triangle2.points[2])
    };

    // Checking possible line segment intersections
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (isLinesIntersecting(firstSegments[i], secondSegments[j]))
                return true;

    // Checking if points of the second triangle are in the first triangle
    for (const vec2& point : triangle2.points)
        if (isPointInside(point, triangle1))
            return true;

    // Checking if points of the first triangle are in the second triangle
    for (const vec2& point : triangle1.points)
        if (isPointInside(point, triangle2))
            return true;

    return false;
}
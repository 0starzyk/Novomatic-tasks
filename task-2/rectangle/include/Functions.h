#pragma once

#include <algorithm>
#include <cmath>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

struct Solution
{
	float x1, x2;
};

Solution solveQuadratic(float a, float b, float c);

bool isPointInside(const sf::Vector2f& point, const sf::CircleShape& circle);

bool isLineIntersecting(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint, const sf::CircleShape& circle);
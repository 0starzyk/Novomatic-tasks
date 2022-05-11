#include "Functions.h"

Solution solveQuadratic(float a, float b, float c)
{
	float determinant = b * b - 4 * a * c;
	return Solution{ (-b - static_cast<float>(sqrt(determinant))) / (2 * a), (-b + static_cast<float>(sqrt(determinant))) / (2 * a) };
}

bool isPointInside(const sf::Vector2f& point, const sf::CircleShape& circle)
{
	if (sqrt(pow(point.x - circle.getPosition().x, 2) + pow(point.y - circle.getPosition().y, 2)) <= circle.getRadius())
		return true;
	return false;
}

bool isLineIntersecting(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint, const sf::CircleShape& circle)
{
	if (firstPoint.x != secondPoint.x)
	{
		float A = (firstPoint.y - secondPoint.y) / (firstPoint.x - secondPoint.x);
		float B = firstPoint.y - A * firstPoint.x;

		float a = A * A + 1;
		float b = 2 * A * B - 2 * circle.getPosition().x - 2 * A * circle.getPosition().y;
		float c = circle.getPosition().x * circle.getPosition().x + circle.getPosition().y * circle.getPosition().y - 2 * circle.getPosition().y * B + B * B - circle.getRadius() * circle.getRadius();

		Solution coords;
		if (b * b - 4 * a * c > 0)
			coords = solveQuadratic(a, b, c);
		else
			return false;

		sf::Vector2f firstInter(coords.x1, A * coords.x1 + B);
		sf::Vector2f secondInter(coords.x2, A * coords.x2 + B);

		if (firstInter.x <= std::max(firstPoint.x, secondPoint.x) && firstInter.x >= std::min(firstPoint.x, secondPoint.x))
			return true;

		if (secondInter.x <= std::max(firstPoint.x, secondPoint.x) && secondInter.x >= std::min(firstPoint.x, secondPoint.x))
			return true;
	}

	else
	{
		sf::Vector2f firstInter(firstPoint.x, sqrt(circle.getRadius() - pow(firstPoint.x - circle.getPosition().x, 2)) + circle.getPosition().y);
		sf::Vector2f secondInter(firstPoint.x, -sqrt(pow(circle.getRadius(), 2) - pow(firstPoint.x - circle.getPosition().x, 2)) + circle.getPosition().y);

		if (firstInter.y <= std::max(firstPoint.y, secondPoint.y) && firstInter.y >= std::min(firstPoint.y, secondPoint.y))
			return true;

		if (secondInter.y <= std::max(firstPoint.y, secondPoint.y) && secondInter.y >= std::min(firstPoint.y, secondPoint.y))
			return true;
	}

	return true;
}
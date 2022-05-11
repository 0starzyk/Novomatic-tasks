#include <iostream>
#include <array>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Functions.h"

struct line
{
	sf::Vector2f first, second;
};

class Rectangle : public sf::RectangleShape
{
public:
	sf::Vector2f getGlobalPoint(int index)
	{
		return getTransform().transformPoint(getPoint(index));
	}
};

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Crazy shapes", sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;

	Rectangle rectangle;
	sf::CircleShape circle;
	sf::CircleShape point;

	sf::Vector2f initialPosition(580.0f, 300.0f);

	window.setFramerateLimit(90);

	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			rectangle.rotate(-1.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			rectangle.rotate(1.0f);

		window.clear(sf::Color::Black);

		// circle
		circle.setRadius(100.0f);
		circle.setPointCount(60);
		circle.setOrigin(sf::Vector2f(circle.getRadius(), circle.getRadius()));
		circle.setFillColor(sf::Color(237, 28, 36));
		circle.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 2, static_cast<float>(window.getSize().y) / 2));

		// rectangle
		rectangle.setSize(sf::Vector2f(150.0f, 200.0f));
		rectangle.setOrigin(sf::Vector2f(rectangle.getSize().x / 2, rectangle.getSize().y / 2));
		rectangle.setPosition(initialPosition);
		rectangle.setFillColor(sf::Color(255, 174, 201));
		
		// point
		point.setRadius(2.0f);
		point.setOrigin(sf::Vector2f(point.getRadius(), point.getRadius()));
		point.setFillColor(sf::Color::Black);
		point.setPosition(initialPosition);

		std::array<line, 4> lines = {
			line{rectangle.getGlobalPoint(0), rectangle.getGlobalPoint(1)},
			line{rectangle.getGlobalPoint(1), rectangle.getGlobalPoint(2)},
			line{rectangle.getGlobalPoint(2), rectangle.getGlobalPoint(3)},
			line{rectangle.getGlobalPoint(3), rectangle.getGlobalPoint(0)},
		};

		for (int i = 0; i < 4; i++)
			if (isPointInside(rectangle.getTransform().transformPoint(rectangle.getPoint(i)), circle) == true || isLineIntersecting(lines[i].first, lines[i].second, circle) == true)
			{
				rectangle.setFillColor(sf::Color(181, 230, 29));
				circle.setFillColor(sf::Color(34, 177, 76));
			}
		
		// drawing
		window.draw(circle);
		window.draw(rectangle);
		window.draw(point);

		window.display();
	}
	return 0;
}
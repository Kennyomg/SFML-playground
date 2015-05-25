#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<iostream>
#include "FPS.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	window.setFramerateLimit(30);
	FPS fps;
	
	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		shape.setPosition(sf::Vector2f(shape.getPosition().x + 1.f, shape.getPosition().y));
		window.clear();
		window.draw(shape);
		window.display();
		fps.update();
		std::cout << "fps: " << fps.getFPS() << std::endl;
	}

	return 0;
}
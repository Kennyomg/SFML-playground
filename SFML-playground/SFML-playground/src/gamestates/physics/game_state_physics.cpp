#include <SFML/Graphics.hpp>
#include <iostream>

#include "game_state_physics.hpp"
#include "../game_state.hpp"

void GameStatePhysics::draw(const float dt)
{
	this->game->window.setView(this->view);

	this->game->window.clear(sf::Color::Black);
	//this->game->window.draw(this->game->background);

	return;
}

void GameStatePhysics::update(const float dt)
{
}

void GameStatePhysics::handleInput()
{
	sf::Event event;

	sf::Vector2f mousePos = this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window), this->view);

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
			/* Close the window */
		case sf::Event::Closed:
		{
			game->window.close();
			break;
		}
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape) this->game->window.close();
			break;
		}
		default: break;
		}
	}

	return;
}

GameStatePhysics::GameStatePhysics(Game* game)
{
	std::cout << "Physics are easy!" << std::endl;
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);
}
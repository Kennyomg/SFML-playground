#ifndef GAME_STATE_PHYSICS_HPP
#define GAME_STATE_PHYSICS_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "../game_state.hpp"
#include "../../gui/gui.hpp"

class GameStatePhysics : public GameState
{
private:

	sf::View view;

public:

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStatePhysics(Game* game);
};

#endif /* GAME_STATE_PHYSICS_HPP */
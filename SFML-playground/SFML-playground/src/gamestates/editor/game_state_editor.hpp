#ifndef GAME_STATE_EDITOR_HPP
#define GAME_STATE_EDITOR_HPP

#include <SFML/Graphics.hpp>

#include "../game_state.hpp"

enum class ActionState { NONE, PANNING, SELECTING };

class GameStateEditor : public GameState
{
private:

	ActionState actionState;

	sf::View gameView;
	sf::View guiView;

	sf::Vector2i panningAnchor;
	float zoomLevel;

	sf::Vector2i selectionStart;
	sf::Vector2i selectionEnd;

public:

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStateEditor(Game* game);
};

#endif /* GAME_STATE_EDITOR_HPP */
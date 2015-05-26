#ifndef GAME_HPP
#define GAME_HPP

#include <stack>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

#include "../managers/texture/texture_manager.hpp"
#include "../gui/gui.hpp"

class GameState;

class Game
{
private:

	void loadTextures();
	void loadStylesheets();
	void loadFonts();

public:

	const static int tileSize = 8;

	std::stack<GameState*> states;

	sf::RenderWindow window;
	TextureManager texmgr;
	sf::Sprite background;

	std::map<std::string, GuiStyle> stylesheets;
	std::map<std::string, sf::Font> fonts;

	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	void setBackground(sf::String &name);

	GameState* peekState();

	void gameLoop();

	Game();
	~Game();
};

#endif /* GAME_HPP */
#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include "GameState.h"
#include "Button.h"

class MainMenuState : public State {
public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~MainMenuState();
	void update (const float& dt);
	void render (sf::RenderTarget* target = NULL);
	void endState();
	void updateInput(const float& dt);
	
	
private:
	sf::RectangleShape _background;
	sf::Font _font;
	Button* _gameStateButton;
	void initKeybinds();
	void initFonts();
};

#endif


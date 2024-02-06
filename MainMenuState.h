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
	void updateButtons();
	void renderButtons(sf::RenderTarget* target = NULL);
	
private:
	sf::RectangleShape _background;
	sf::Font _font;
	std::map<std::string, Button*> _buttons;  
	void initKeybinds();
	void initFonts();
	void initButtons();
};

#endif


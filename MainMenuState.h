#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include "GameState.h"


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
	void initKeybinds();
	
};

#endif


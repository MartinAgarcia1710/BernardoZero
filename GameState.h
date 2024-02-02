#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "State.h"

class GameState : public State {
public:
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	~GameState();
	void update (const float& dt);
	void render (sf::RenderTarget* target = NULL);
	void endState();
	void updateInput(const float& dt);
private:
	Entity _player;
	void initKeybinds();
};

#endif


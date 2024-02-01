#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "State.h"

class GameState : public State {
public:
	GameState(sf::RenderWindow* window);
	~GameState();
	void update (const float& dt);
	void render (sf::RenderTarget* target = NULL);
	void endState();
	void updateKeyBinds(const float& dt);
private:
	Entity _player;
};

#endif


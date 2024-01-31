#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "..\State.h"

class GameState : public State {
public:
	GameState(sf::RenderWindow* window);
	~GameState();
	void update ( const float &dt);
	void render (sf::RenderTarget* target = nullptr );
	void endState();
private:
};

#endif


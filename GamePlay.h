#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "GameState.h"



enum GAME_STATUS{
	PAUSE,
	RUNNING
};
class GamePlay {
public:
	GamePlay();
	virtual ~GamePlay();
	void updateDeltaTime();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
	void endApplication();
	
	
private:
	sf::RenderWindow *_window;
	sf::Event _sfEvent;
	void initWindow();
	void iniStates();
	sf::Clock _deltaTimeClock;
	float _deltaTime;
	std::stack<State*> _states;
	
};

#endif


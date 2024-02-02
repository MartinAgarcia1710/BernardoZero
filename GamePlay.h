#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "MainMenuState.h"



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
	
	
	sf::Clock _deltaTimeClock;
	float _deltaTime;
	std::stack<State*> _states;
	std::map<std::string, int> _supportedKeys;
	void initWindow();
	void initKeys();
	void iniStates();
};

#endif


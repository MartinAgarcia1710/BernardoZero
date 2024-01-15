#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Rafael.h"
#include <SFML/Graphics.hpp>

enum GAME_STATUS{
	PAUSE,
	RUNNING
};
class GamePlay {
public:
	GamePlay();
	void cmd();
	void update(sf::RenderWindow & rw);
	void draw(sf::RenderWindow &w);
	sf::View getView();
private:
	Rafael _rafa;
	sf::View _vie;
	GAME_STATUS _gstat;
	
};

#endif


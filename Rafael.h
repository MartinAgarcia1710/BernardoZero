#ifndef RAFAEL_H
#define RAFAEL_H
#include <SFML/Graphics.hpp>

enum STATUS {
	IDLE,
	WALK_RIGHT,
	WALK_LEFT,
	WALK_DOWN,
	WALK_UP,
	ATTACK
		
};

class Rafael {
public:
		
	Rafael();
	void cmd(sf::View &v);
	void update(sf::RenderWindow &rw, sf::View &v);
	sf::Sprite& getDraw();
	
private:
	sf::Sprite _sp;
	sf::Texture _tex;
	sf::Vector2f _speed;
	float _frame;
	STATUS _stat;
};

#endif


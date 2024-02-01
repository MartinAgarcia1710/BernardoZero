#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/system.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Entity {
public:
	Entity();
	virtual ~Entity();
	virtual void move(const float& dt, const float dir_x, const float dir_y);
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
protected:
	sf::RectangleShape _shape;
	float _movementSpeed;
private:
	
};

#endif


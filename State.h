#ifndef STATE_H
#define STATE_H

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



class State {
public:
	State(sf::RenderWindow* window);
	virtual ~State();
	
	virtual void endState() = 0;
	
	virtual void update(const  float &dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
	
private:
	sf::RenderWindow* _window;
	std::vector<sf::Texture*> _textures;
};

#endif


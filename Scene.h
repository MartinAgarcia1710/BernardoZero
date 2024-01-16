#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics.hpp>
class Scene {
public:
	Scene();
	
private:
	sf::Texture _tex;
	sf::Sprite _sp;
	int map[90][90];
	
};

#endif


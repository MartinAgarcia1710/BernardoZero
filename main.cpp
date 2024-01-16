#include <SFML/Graphics.hpp>
#include "Rafael.h"
#include "GamePlay.h"
#include "Scene.h"
int main(int argc, char *argv[]){
	sf::RenderWindow w(sf::VideoMode(1920, 1080),"Bernardo Zero");
	w.setFramerateLimit(60);
	GamePlay game;
	Scene sce;
	sf::Texture t;
	if(!t.loadFromFile("sprites/backPelado.png")){
		system("echo EROR DE IMAGEN BACK&pause");
	}
	
	sf::Sprite spr;
	spr.setTexture(t);
	spr.setOrigin(t.getSize().x/2, t.getSize().y/2);
	spr.setPosition(0, 0);
	while(w.isOpen()) {
		sf::Event e;
		while(w.pollEvent(e)) {
			if(e.type == sf::Event::Closed)
				w.close();	
		}
		
		
		game.cmd();
		game.update(w);
		
		w.clear();
		w.draw(spr);
		
		w.setView(game.getView());
		game.draw(w);
		w.display();
	}
	return 0;
}


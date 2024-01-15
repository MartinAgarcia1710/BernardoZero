#include "GamePlay.h"
#include "Rafael.h"
#include <SFML/Graphics.hpp>
GamePlay::GamePlay() {
	_gstat = GAME_STATUS::RUNNING;
	_vie.setSize(1920, 1080);
	_vie.setCenter(0,0);
	
}
void GamePlay::cmd(){
	if(_gstat == GAME_STATUS::RUNNING){
		_rafa.cmd(_vie);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)){
			_gstat = GAME_STATUS::PAUSE;
		}
	}else{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)){
			_gstat = GAME_STATUS::RUNNING;
		}
	}
	
}
void GamePlay::update(sf::RenderWindow & rw){
	if(_gstat == GAME_STATUS::RUNNING){
		
		_rafa.update(rw, _vie);
	}
	
}
void GamePlay::draw(sf::RenderWindow &w){
	w.draw(_rafa.getDraw());
}

sf::View GamePlay::getView(){
	return _vie;
}

#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
	: State(window){
}
 
GameState::~GameState() {
	
}

void GameState::update (const  float &dt ) {
	
	this->updateKeyBinds(dt);
	this->_player.update(dt);
}

void GameState::render (sf::RenderTarget* target) {
	
	this->_player.render(this->_window);
}

void GameState::endState(){
	std::cout << "Ending GameState\n";
}

void GameState::updateKeyBinds(const float& dt){
	this->checkForQuit();
	
}

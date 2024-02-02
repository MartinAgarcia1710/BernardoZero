#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys){
	this->initKeybinds();
}
 
GameState::~GameState() {
	
}

void GameState::update (const  float &dt ) {
	
	this->updateInput(dt);
	this->_player.update(dt);
}

void GameState::render (sf::RenderTarget* target) {
	if(!target){
		target = this->_window;
	}
	this->_player.render(target);
}

void GameState::endState(){
	std::cout << "Ending GameState\n";
}

void GameState::updateInput(const float& dt){
	
	this->checkForQuit();
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->_keybinds.at("MOVE_LEFT")))){
		this->_player.move(dt, -1.f, 0.f);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->_keybinds.at("MOVE_RIGHT")))){
		this->_player.move(dt, 1.f, 0.f);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->_keybinds.at("MOVE_UP")))){
		this->_player.move(dt, 0.f, -1.f);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->_keybinds.at("MOVE_DOWN")))){
		this->_player.move(dt, 0.f, 1.f);
	}
	
}

void GameState::initKeybinds(){
	std::ifstream ifs("config/gamestate_keybinds.ini");
	
	if(ifs.is_open()){
		std::string key = "";
		std::string key2 = "";
		while(ifs >> key >> key2){
			this->_keybinds[key] = this->_supportedKeys->at(key2);
			
		}
	}else{
		std::cout << "ERROR\n";
	}
	
	ifs.close();
	
}

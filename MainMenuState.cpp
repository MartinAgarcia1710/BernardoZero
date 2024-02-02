#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys){
	this->initKeybinds();
	
	this->_background.setSize(sf::Vector2f(window->getSize().x,window->getSize().y));
	this->_background.setFillColor(sf::Color::Cyan);
	
}

MainMenuState::~MainMenuState() {
	
}

void MainMenuState::update (const  float &dt ) {
	
	this->updateInput(dt);
	
}

void MainMenuState::render (sf::RenderTarget* target) {
	if(!target){
		target = this->_window;
	}
	target->draw(this->_background);
}

void MainMenuState::endState(){
	std::cout << "Ending GameState\n";
}

void MainMenuState::updateInput(const float& dt){
	
	this->checkForQuit();
	
}

void MainMenuState::initKeybinds(){
	
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

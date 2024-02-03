#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) {
	this->_window = window;
	this->_supportedKeys = supportedKeys;
	//system("pause");
	this->_quit = false;
}

State::~State() {
	
}

void State::checkForQuit(){
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->_keybinds.at("CLOSE")))){
		this->_quit = true;
	}
}

const bool& State::getQuit()const{
	return this->_quit;
}

void State::initKeybinds(){
	
} 

void State::updateMousePositions(){
	this->_mousePosScreen = sf::Mouse::getPosition();
	this->_mousePosWindow = sf::Mouse::getPosition(*this->_window);
	this->_mousePosView = this->_window->mapPixelToCoords(sf::Mouse::getPosition(*this->_window));
}

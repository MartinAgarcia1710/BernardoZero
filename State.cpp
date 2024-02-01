#include "State.h"

State::State(sf::RenderWindow* window) {
	this->_window = window;
	this->_quit = false;
}

State::~State() {
	
}

void State::checkForQuit(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
		this->_quit = true;
	}
}

const bool& State::getQuit()const{
	return this->_quit;
}

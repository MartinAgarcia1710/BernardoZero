#include "GameState.h"
GameState::GameState(sf::RenderWindow* window){
	//: State(window)
}

GameState::~GameState() {
	
}

void GameState::update (const  float &dt ) {
	std::cout << "ESTO ES GAMESTATE\n";
}

void GameState::render (sf::RenderTarget* target) {
	
}

void GameState::endState(){
	
}

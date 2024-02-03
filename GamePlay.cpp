#include "GamePlay.h"
#include "Rafael.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>

GamePlay::GamePlay(){
	this->initWindow();
	this->initKeys(); 
	this->iniStates();
	
}

void GamePlay::updateDeltaTime(){
	this->_deltaTime = this->_deltaTimeClock.restart().asSeconds();
}

void GamePlay::updateSFMLEvents(){
	while(this->_window->pollEvent(this->_sfEvent)){
		if(this->_sfEvent.type == sf::Event::Closed){
			this->_window->close();
		}
	}
}

void GamePlay::update(){
	this->updateSFMLEvents();
	
	if(!this->_states.empty()){
		this->_states.top()->update(this->_deltaTime);
		if(this->_states.top()->getQuit()){
			this->_states.top()->endState();
			delete this->_states.top();
			this->_states.pop();
		}
	}else{
		this->endApplication();
		this->_window->close();
	}
	
}

void GamePlay::render(){
	this->_window->clear();
	
	if(!this->_states.empty()){
		this->_states.top()->render();
	}
	this->_window->display();
}

void GamePlay::run(){
	while(this->_window->isOpen()){
		this->updateDeltaTime();
		this->update();
		this->render();
	}
}

void GamePlay::initWindow(){
	std::ifstream ifs("config/win.ini");
	
	std::string title = "None";
	sf::VideoMode window_bounds(800, 600);
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;
	
	
	if(ifs.is_open()){
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}
	
	ifs.close();
	
	this->_window = new sf::RenderWindow(window_bounds, title);
	this->_window->setFramerateLimit(framerate_limit);
	this->_window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void GamePlay::iniStates(){
	this->_states.push(new MainMenuState(this->_window, &this->_supportedKeys));
	//this->_states.push(new GameState(this->_window, &this->_supportedKeys));
}
GamePlay::~GamePlay(){
	delete this->_window;
	
	while(!this->_states.empty()){
		delete this->_states.top();
		this->_states.pop();
	}
	
}

void GamePlay::endApplication(){
	std::cout << "Ending App\n";
}

void GamePlay::initKeys(){
	
	std::ifstream ifs("config/supported_keys.ini");
	
	if(ifs.is_open()){
		std::string key = "";
		int key_value = 0;
		while(ifs >> key >> key_value){
			this->_supportedKeys[key] = key_value;
			
		}
	}
	
	ifs.close();
	
	for(auto i : this->_supportedKeys){
		std::cout << i.first << " " << i.second << "\n";
	}
}

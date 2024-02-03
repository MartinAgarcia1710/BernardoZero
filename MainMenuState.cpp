#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys){
	this->initFonts();
	this->initKeybinds();
	this->_gameStateButton = new Button(100, 100, 150, 50, &this->_font, "NEW GAME",
	sf::Color(70,70,70,200),sf::Color(150,150,150,255), sf::Color(20,20,20,200));
	this->_background.setSize(sf::Vector2f(window->getSize().x,window->getSize().y));
	this->_background.setFillColor(sf::Color::Cyan);
	
}

MainMenuState::~MainMenuState() {
	delete this->_gameStateButton;
}

void MainMenuState::update (const  float &dt ) {
	this->updateMousePositions();
	this->updateInput(dt);
	this->_gameStateButton->update(this->_mousePosView);
}

void MainMenuState::render (sf::RenderTarget* target) {
	if(!target){
		target = this->_window;
	}
	target->draw(this->_background);
	this->_gameStateButton->render(target);
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
void MainMenuState::initFonts(){
	if(!this->_font.loadFromFile("fonts/Mario-Kart-DS.ttf")){
		throw("ERROR - MAINMENUSTATE - COULD NOT LOAD FONT FROM FILE");
	}
}

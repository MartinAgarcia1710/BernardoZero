#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys){
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	
	this->_background.setSize(sf::Vector2f(window->getSize().x,window->getSize().y));
	this->_background.setFillColor(sf::Color::Cyan);
	
}

MainMenuState::~MainMenuState() {
	auto it = this->_buttons.begin();
	for(it = this->_buttons.begin(); it != this->_buttons.end(); ++it){
		delete it->second;
	}
	
}

void MainMenuState::update (const  float &dt ) {
	this->updateMousePositions();
	this->updateInput(dt);
	
	this->updateButtons();
	
}

void MainMenuState::render (sf::RenderTarget* target) {
	if(!target){
		target = this->_window;
	}
	target->draw(this->_background);
	//this->_gameStateButton->render(target);
	this->renderButtons(target);
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
void MainMenuState::initButtons(){
	this->_buttons["GAME_STATE"] = new Button(100, 100, 150, 50, &this->_font, "New Game",
		sf::Color(70,70,70,200), sf::Color(150,150,150,255),sf::Color(20,20,20,200));
	
	this->_buttons["EXIT_STATE"] = new Button(100, 300, 150, 50, &this->_font, "Quit",
	    sf::Color(100,100,100,200), sf::Color(150,150,150,255),sf::Color(20,20,20,200));
}

void MainMenuState::updateButtons(){
	
	for(auto &it : this->_buttons){
		it.second->update(this->_mousePosView);
	}
	if(this->_buttons["GAME_STATE"]->isPressed()){
		//this->_states.push(new MainMenuState(this->_window, &this->_supportedKeys));
	}
	if(this->_buttons["EXIT_STATE"]->isPressed()){
		this->_quit = true;
	}
}

void MainMenuState::renderButtons(sf::RenderTarget* target){
	
	for(auto &it : this->_buttons){
		it.second->render(target);
	}
}

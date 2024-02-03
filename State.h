#ifndef STATE_H
#define STATE_H

#include "Entity.h"
class State {
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~State();
	
	const bool& getQuit()const;
	virtual void checkForQuit();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const  float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
	virtual void endState() = 0;
	virtual void updateMousePositions();
protected:
	sf::RenderWindow* _window;
	std::map<std::string, int>* _supportedKeys;
	std::map<std::string, int> _keybinds;
	std::vector<sf::Texture*> _textures;
	bool _quit;
	sf::Vector2i _mousePosScreen;
	sf::Vector2i _mousePosWindow;
	sf::Vector2f _mousePosView;
	
	virtual void initKeybinds() = 0;
private:
	
};

#endif


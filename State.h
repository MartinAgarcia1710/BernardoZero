#ifndef STATE_H
#define STATE_H

#include "Entity.h"
class State {
public:
	State(sf::RenderWindow* window);
	virtual ~State();
	
	const bool& getQuit()const;
	virtual void checkForQuit();
	virtual void updateKeyBinds(const float& dt) = 0;
	virtual void update(const  float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
	virtual void endState() = 0;
protected:
	sf::RenderWindow* _window;
	std::vector<sf::Texture*> _textures;
	bool _quit;
private:
};

#endif


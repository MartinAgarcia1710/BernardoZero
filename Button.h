#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/system.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum button_states{
	BTN_IDLE = 0,
	BTN_HOVER,
	BTN_ACTIVE
}; 
class Button {
public:
	Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor,sf::Color activeColor);
	~Button();
	const bool isPressed() const;
	void update(const sf::Vector2f mousePo);
	void render(sf::RenderTarget* target);
	
private:
	short unsigned _buttonState;
	sf::RectangleShape _shape;
	sf::Font* _font;
	sf::Text _text;
	sf::Color _idleColor;
	sf::Color _hoverColor;
	sf::Color _activeColor;
};

#endif


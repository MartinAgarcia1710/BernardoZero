#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor,sf::Color activeColor) {
	this->_buttonState = BTN_IDLE;
	this->_shape.setPosition(sf::Vector2f(x, y));
	this->_shape.setSize(sf::Vector2f(width, height));
	this->_font = font;
	this->_text.setFont(*this->_font);
	this->_text.setString(text);
	this->_text.setFillColor(sf::Color::Black);
	this->_text.setCharacterSize(12);
	
	this->_text.setPosition(
		this->_shape.getPosition().x + (this->_shape.getGlobalBounds().width / 2.f) - this->_text.getGlobalBounds().width / 2.f, 
		this->_shape.getPosition().y + (this->_shape.getGlobalBounds().height / 2.f) - this->_text.getGlobalBounds().height / 2.f);
	
	this->_idleColor = idleColor;
	this->_hoverColor = hoverColor;
	this->_activeColor = activeColor;
	
	this->_shape.setFillColor(this->_idleColor);
	
}

Button::~Button() {
	
}

void Button::render(sf::RenderTarget* target){
	target->draw(this->_shape);
	target->draw(this->_text);
}

void Button::update(const sf::Vector2f mousePo){
	
	this->_buttonState = BTN_IDLE;
	
	if(this->_shape.getGlobalBounds().contains(mousePo)){
		this->_buttonState = BTN_HOVER;
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			this->_buttonState = BTN_ACTIVE;
		}
	}
	switch(this->_buttonState){
		case BTN_IDLE:
			this->_shape.setFillColor(this->_idleColor);
			break;
		case BTN_HOVER:
			this->_shape.setFillColor(this->_hoverColor);
			break;
		case BTN_ACTIVE:
			this->_shape.setFillColor(this->_activeColor);
			break;
		default:
			this->_shape.setFillColor(sf::Color::Black);
			break;
	}
}
const bool Button::isPressed() const{
	if(this->_buttonState == BTN_ACTIVE){
		return true;
	}else{
		return false;
	}
}

#include "Entity.h"

Entity::Entity() {
	this->_shape.setSize(sf::Vector2f(50.f, 50.f));
	this->_shape.setFillColor(sf::Color::White);
	this->_movementSpeed = 100.f;
}

Entity::~Entity() {
	
}

void Entity::update(const float& dt){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		this->move(dt, -1.f, 0.f);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		this->move(dt, 1.f, 0.f);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		this->move(dt, 0.f, -1.f);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		this->move(dt, 0.f, 1.f);
	}
}

void Entity::render(sf::RenderTarget* target){
	target->draw(this->_shape);
}

void Entity::move(const float& dt, const float dir_x, const float dir_y){
	this->_shape.move(dir_x * this->_movementSpeed * dt, dir_y * this->_movementSpeed * dt);
	
}

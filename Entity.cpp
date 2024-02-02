#include "Entity.h"

Entity::Entity() {
	this->_shape.setSize(sf::Vector2f(50.f, 50.f));
	this->_shape.setFillColor(sf::Color::White);
	this->_movementSpeed = 100.f;
}

Entity::~Entity() {
	
}

void Entity::update(const float& dt){
	
}

void Entity::render(sf::RenderTarget* target){
	target->draw(this->_shape);
}

void Entity::move(const float& dt, const float dir_x, const float dir_y){
	this->_shape.move(dir_x * this->_movementSpeed * dt, dir_y * this->_movementSpeed * dt);
	
}

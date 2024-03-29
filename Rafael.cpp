#include "Rafael.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>

Rafael::Rafael() {
	if(!_tex.loadFromFile("sprites/plantillaIdle128x128.png")){
		system("echo EROR DE IMAGEN RAFAEL&pause");
	}
	sf::Vector2u textureSize = _tex.getSize();
	_sp.setTexture(_tex);
	//sf::Sprite sp(_tex, sf::IntRect(textureSize.x * .1, 0,textureSize.x, textureSize.y));
	_sp.setTextureRect(sf::IntRect(0, 0, 128, 128) );
	_sp.setScale(0.80,0.80);
	_sp.setPosition(0,0);
	_stat = STATUS::IDLE;
	_speed = {0, 0};
	_sp.setOrigin(128/2, 128/2);
	_frame = 0;
}

void Rafael::cmd(sf::View &v){
	//&& _sp.getPosition().x >= -626
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && _sp.getPosition().x >= -1370 ){
		_stat = STATUS::WALK_LEFT;
		if(_sp.getPosition().x < 500){
		v.setCenter(_sp.getPosition());
		}
		//v.move(_speed.x, _speed.y);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& _sp.getPosition().x <= 1370 ){
		_stat = STATUS::WALK_RIGHT;
		v.setCenter(_sp.getPosition());
		//v.move(_speed.x, _speed.y);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& _sp.getPosition().y >= -1370){
		_stat = STATUS::WALK_UP;
		v.setCenter(_sp.getPosition());
		//v.move(_speed.x, _speed.y);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && _sp.getPosition().y <= 1370){
		_stat = STATUS::WALK_DOWN;
		v.setCenter(_sp.getPosition());
		//v.move(_speed.x, _speed.y);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		_stat = STATUS::ATTACK;
	}
	
}
void Rafael::update(sf::RenderWindow &rw, sf::View &v){
	_frame += 0.25;
	sf::Sprite sp;
	//_sp.setTextureRect(sf::IntRect(0 + _frame * 128, 0, 128, 128));
	_speed = {};
	v.move(_speed.x, _speed.y);
	switch(_stat){
	case IDLE:
		break;
	case WALK_DOWN:
		_speed.y = 4;
		_tex.loadFromFile("sprites/caminandoAbajo.png");
		_sp.setTexture(_tex);
		_sp.setTextureRect(sf::IntRect(0 + _frame *128, 0, 128, 128) );
		_sp.move(_speed);
		
		_stat = STATUS::IDLE;
		
		break;
	case WALK_LEFT:
		
		_speed.x = -4;
		_sp.setTexture(_tex);
		_sp.setTextureRect(sf::IntRect(128*3, 0, 128, 128) );
		_sp.move(_speed);
		_stat = STATUS::IDLE;
		break;
	case WALK_RIGHT:
		_speed.x = 4;
		_sp.setTexture(_tex);
		_sp.setTextureRect(sf::IntRect(128*2, 0, 128, 128) );
		_sp.move(_speed);
		_stat = STATUS::IDLE;
		break;
	case WALK_UP:
		_speed.y = -4;
		_sp.setTexture(_tex);
		_sp.setTextureRect(sf::IntRect(128, 0, 128, 128) );
		_sp.move(_speed);
		_stat = STATUS::IDLE;
		break;
	case ATTACK:
		break;
	default:
		break;
	}
	_sp.move(_speed);
	
	
		
}

sf::Sprite& Rafael::getDraw(){
	
	return _sp;
}


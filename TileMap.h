#ifndef TILEMAP_H
#define TILEMAP_H
#include <SFML/Graphics.hpp>
#include <cstring>
#include <iostream>
#include "string.h"
class TileMap : public sf::Drawable, public sf::Transformable{
public:
	TileMap();
	
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			// apply the transform
			states.transform *= getTransform();
			
			// apply the tileset texture
			states.texture = &m_tileset;
			
			// draw the vertex array
			target.draw(m_vertices, states);
		}
		
		sf::VertexArray m_vertices;
		sf::Texture m_tileset;
};

#endif

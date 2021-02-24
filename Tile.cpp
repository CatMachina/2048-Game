#include "pch.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include "Tile.h"

using namespace sf;

Tile::Tile()
{

}

void Tile::init(int value, Vector2i position)
{
	// Init values
	m_Value = value;
	m_GBPosition.x = position.x;
	m_GBPosition.y = position.y;
	m_Updated = 0;

	// Get filename
	std::stringstream filename;
	filename << "graphics/" << value << ".png";
	m_TileSprite = Sprite(TextureHolder::getTexture(filename.str()));
	m_TileSprite.setPosition(TILE_SIZE * position.y + 5 * (position.y + 1), 200 + TILE_SIZE * position.x + 5 * (position.x + 1));
}

void Tile::setUpdate(bool update)
{
	m_Updated = update;
}

Vector2i Tile::getPosition()
{
	return m_GBPosition;
}

Sprite Tile::getTileSprite()
{
	return m_TileSprite;
}

int Tile::getValue()
{
	return m_Value;
}

bool Tile::isUpdated()
{
	return m_Updated;
}
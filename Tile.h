#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

using namespace sf;

class Tile
{
private:
	
	// How big tiles are gonna be
	const int TILE_SIZE = 150;

	// How fast square is gonna move * number of tiles away
	const int m_BASESPEED = 200;

	// Value of square 2, 4, 8, etc.
	int m_Value;
	bool m_Updated;

	// For graphics
	Sprite m_TileSprite;

	Vector2i m_GBPosition;

public:
	// Placeholder value
	Tile();

	Sprite getTileSprite();
	
	// To actually make it?
	void init(int value, Vector2i position);
	void setUpdate(bool update);

	// Getters
	Vector2i getPosition();
	int getValue();
	bool isUpdated();

};


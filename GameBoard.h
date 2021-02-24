#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Tile.h"

using namespace sf;
using namespace std;

class GameBoard
{
private:
	// 4x4
	const static int SIZE = 4;
	const int WIN = 2048;

	// Actual board
	Tile m_GB[SIZE][SIZE];

	// Graphics
	Sprite m_GBSprite;

public:

	GameBoard();

	// Spawn square after every move
	void randomSpawn(int seed);

	void reinit();

	int updateBoard(int direction);
	bool win();
	bool lose();

	Sprite getGBSprite();
	Sprite getTileSprite(int row, int col);
	int getTileValue(int row, int col);

};


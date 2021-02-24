#include "pch.h"
#include <SFML/Graphics.hpp>
#include "GameBoard.h"

using namespace std;
using namespace sf;

GameBoard::GameBoard()
{
	// Gameboard graphics
	m_GBSprite = Sprite(TextureHolder::getTexture("graphics/Board.png"));
	m_GBSprite.setPosition(0, 200);

	// Set elements to NULL;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			m_GB[i][j].init(0, Vector2i(i, j));
		}
	}
}

void GameBoard::reinit()
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			m_GB[i][j].init(0, Vector2i(i, j));
		}
	}
}

void GameBoard::randomSpawn(int seed)
{
	srand((int)time(0) + seed);
	int row, col;
	do
	{
		row = rand() % 4;
		col = rand() % 4;
	} while (m_GB[row][col].getValue() != 0);
	int randVal = rand() % 10;
	randVal = !randVal ? 4 : 2;
	m_GB[row][col].init(randVal, Vector2i(row, col));

}

int GameBoard::updateBoard(int direction)
{
	// ROW = X
	// COL = Y
	// 0 = Up
	// 1 = Down
	// 2 = Left
	// 3 = Right
	// If this works, maybe compress later
	bool changed = 0;
	int sum = 0;
	if (direction <= 1)
	{
		// Down : up
		int start = direction ? 3 : 0;
		int end = direction ? -1 : 4;
		int inc = direction ? -1 : 1;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = start; j != end; j += inc)
			{
				if (m_GB[j][i].getValue() == 0)
					continue;
				int k = 0;
				while (0 <= j - (k + 1) * inc && j - (k + 1) * inc <= 3 && m_GB[j - (k + 1) * inc][i].getValue() == 0) k++;
				if (0 <= j - (k + 1) * inc && j - (k + 1) * inc <= 3 && m_GB[j - (k + 1) * inc][i].getValue() == m_GB[j][i].getValue() && !m_GB[j - (k + 1) * inc][i].isUpdated())
				{
					m_GB[j - (k + 1) * inc][i].init(m_GB[j][i].getValue() * 2, Vector2i(j - (k + 1) * inc, i));
					m_GB[j - (k + 1) * inc][i].setUpdate(1);
					m_GB[j][i].init(0, m_GB[j][i].getPosition());
					changed = 1;
					sum += m_GB[j - (k + 1) * inc][i].getValue();
				}
				else if (k != 0)
				{
					m_GB[j - k * inc][i].init(m_GB[j][i].getValue(), Vector2i(j - k * inc, i));
					m_GB[j][i].init(0, m_GB[j][i].getPosition());
					changed = 1;
				}
			}
		}
	}
	else
	{
		// Left : Right
		int start = direction == 2 ? 0 : 3;
		int end = direction == 2 ? 4 : -1;
		int inc = direction == 2 ? 1 : -1;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = start; j != end; j += inc)
			{
				if (m_GB[i][j].getValue() == 0)
					continue;
				int k = 0;
				while (0 <= j - (k + 1) * inc && j - (k + 1) * inc <= 3 && m_GB[i][j - (k + 1) * inc].getValue() == 0) k++;
				if (0 <= j - (k + 1) * inc && j - (k + 1) * inc <= 3 && m_GB[i][j - (k + 1) * inc].getValue() == m_GB[i][j].getValue() && !m_GB[i][j - (k + 1) * inc].isUpdated())
				{
					m_GB[i][j - (k + 1) * inc].init(m_GB[i][j].getValue() * 2, Vector2i(i, j - (k + 1) * inc));
					m_GB[i][j - (k + 1) * inc].setUpdate(1);
					m_GB[i][j].init(0, m_GB[i][j].getPosition());
					changed = 1;
					sum += m_GB[i][j - (k + 1) * inc].getValue();
				}
				else if (k != 0)
				{
					m_GB[i][j - k * inc].init(m_GB[i][j].getValue(), Vector2i(i, j - k * inc));
					m_GB[i][j].init(0, m_GB[i][j].getPosition());
					changed = 1;
				}
			}
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j< 4; ++j)
		{
			m_GB[i][j].setUpdate(0);
		}
	}

	if (!changed)
		return -1;
	return sum;
}

bool GameBoard::win()
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if (m_GB[i][j].getValue() == WIN)
				return 1;
		}
	}
	return 0;
}

bool GameBoard::lose()
{
	int mx[4] = { 1, -1, 0, 0 };
	int my[4] = { 0, 0, -1, 1 };
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if (m_GB[i][j].getValue() == 0)
				return 0;
			bool ok = 0;
			for (int k = 0; k < 4; ++k)
			{
				int nx = i + mx[k];
				int ny = j + my[k];
				if (0 <= nx && nx <= 3 && 0 <= ny && ny <= 3)
				{
					if (m_GB[nx][ny].getValue() == m_GB[i][j].getValue())
						ok = 1;
				}
			}
			if (ok)
				return 0;
		}
	}
	return 1;
}


Sprite GameBoard::getGBSprite()
{
	return m_GBSprite;
}

Sprite GameBoard::getTileSprite(int row, int col)
{
	return m_GB[row][col].getTileSprite();
}

int GameBoard::getTileValue(int row, int col)
{
	return m_GB[row][col].getValue();
}
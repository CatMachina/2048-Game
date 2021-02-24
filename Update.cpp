#include "pch.h"
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include <algorithm>
using namespace sf;

void Engine::update(float milliseconds)
{
	m_Inhibit -= milliseconds;

	int direction = -1;
	if (m_Up)
		direction = 0;
	else if (m_Down)
		direction = 1;
	else if (m_Left)
		direction = 2;
	else if (m_Right)
		direction = 3;

	// If moved, update board
	if (direction != -1)
	{
		int addScore;
		if ((addScore = m_GameBoard.updateBoard(direction)) >= 0)
		{
			m_HUD.updateScore(addScore);
			m_HUD.updateHiScore(max(m_HUD.getHiScore(), m_HUD.getScore()));
			m_GameBoard.randomSpawn(milliseconds);
		}
		else
			// If nothing happened, let them move again
			m_Inhibit = 0;
		// hi :)
	}
	m_Up = m_Down = m_Left = m_Right = 0;
}
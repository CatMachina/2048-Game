#include "pch.h"
#include <SFML/Graphics.hpp>
#include "Engine.h"

void Engine::draw()
{
	m_Window.clear(Color::Color(250, 248, 239, 255));

	m_Window.setView(m_View);
	m_Window.draw(m_GameBoard.getGBSprite());
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (m_GameBoard.getTileValue(i, j))
			{
				m_Window.draw(m_GameBoard.getTileSprite(i, j));
			}
		}
	}

	m_Window.draw(m_HUD.getScoreboard());
	m_Window.draw(m_HUD.getHiScoreboard());
	m_Window.draw(m_HUD.getTitle());
	m_Window.draw(m_HUD.getSBScore());
	m_Window.draw(m_HUD.getSBHiScore());
	m_Window.draw(m_HUD.getTScore());
	m_Window.draw(m_HUD.getTHiScore());

	if(m_Pause)
		m_Window.draw(m_HUD.getNotPlaying());
	if (m_Win)
		m_Window.draw(m_HUD.getWLP("You Win!"));
	else if (m_Lose)
		m_Window.draw(m_HUD.getWLP("You Lose!"));
	else if (m_Pause)
		m_Window.draw(m_HUD.getWLP("Press ENTER to Play!"));

	m_Window.display();
}

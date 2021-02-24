#include "pch.h"
#include "Engine.h"
#include <algorithm>

Engine::Engine()
{
	// Initializing the window of the game and stuff
	Vector2f resolution;
	resolution.x = 625;
	resolution.y = 825;
	
	m_Window.create(VideoMode(resolution.x, resolution.y), "2048", Style::Resize);

	m_View = View(FloatRect(0, 0, resolution.x, resolution.y));
}

void Engine::run()
{
	Clock clock;

	while (m_Playing)
	{

		m_GameBoard.randomSpawn(clock.getElapsedTime().asMicroseconds());
		m_GameBoard.randomSpawn(clock.getElapsedTime().asMicroseconds());

		m_Pause = 1;

		while (m_Playing)
		{
			Time time = clock.restart();
			float asMilliseconds = time.asMilliseconds();
			input();
			if ((m_Win || m_Lose) && m_Pause == 0)
				break;
			m_Win = m_GameBoard.win();
			m_Lose = m_GameBoard.lose();
			while (!m_Pause && (m_Win || m_Lose) && clock.getElapsedTime().asMilliseconds() < 800);
			m_Pause = m_Pause || m_Win || m_Lose;
			if (!m_Pause)
				update(asMilliseconds);
			draw();
		}

		m_HUD.storeHiScore();
		m_HUD.updateScore(-m_HUD.getScore());
		m_GameBoard.reinit();
	}
}
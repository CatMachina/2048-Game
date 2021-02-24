#include "pch.h"
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include <iostream>

using namespace sf;

void Engine::input()
{
	Event event;
	if (m_Window.pollEvent(event))
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			m_Playing = 0;
		}

		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			m_Pause = 0;
		}

		if (Keyboard::isKeyPressed(Keyboard::P))
		{
			m_Pause = 1;
		}

		if (m_Inhibit <= 0 && !m_Pause)
		{
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				m_Up = 1;
				m_Inhibit = INHIBIT;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				m_Down = 1;
				m_Inhibit = INHIBIT;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				m_Left = 1;
				m_Inhibit = INHIBIT;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				m_Right = 1;
				m_Inhibit = INHIBIT;
			}
		}
	}
}
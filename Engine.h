#pragma once
#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "HUD.h";

using namespace sf;

class Engine
{
private:
	// TextureHolder for easy graphics and better RAM?
	TextureHolder th;

	// For HUD;
	HUD m_HUD;

	// How big tiles are gonna be
	const int TILE_SIZE = 200;

	// Creates window to do stuff
	RenderWindow m_Window;

	// Different views of the window to simultaneously do things
	View m_View;

	GameBoard m_GameBoard;

	// User should be able to quit and pause
	bool m_Playing = 1;
	bool m_Pause = 0;

	// Moving
	bool m_Up = 0;
	bool m_Down = 0;
	bool m_Left = 0;
	bool m_Right = 0;
	
	// Inhibit moving for a certain amount of time so animation can finish (in milliseconds)
	const int INHIBIT = 40;
	int m_Inhibit = 0;

	bool m_Lose = 0;
	bool m_Win = 0;

	// Essential functions for game functionality
	void input();
	void update(float milliseconds);
	void draw();

public:
	Engine();
	void run();

};
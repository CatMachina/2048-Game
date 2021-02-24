#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

class HUD
{
private:

	Font m_Font;
	Font m_Bold;

	const int CHAR_SIZE_1 = 36;
	Text m_Score;
	int m_score;
	Text m_HiScore;
	int m_hiScore = 0;

	const int CHAR_SIZE_2 = 100;
	Text m_Title;

	Text m_SBScore;
	Text m_SBHiScore;

	RectangleShape m_ScoreBoard;
	RectangleShape m_HiScoreBoard;
	RectangleShape m_NotPlaying;

	Text m_Start;
	Text m_Win;
	Text m_Lose;
	
	const int WLP_SIZE = 54;
	Text m_WLP;

	std::stringstream text;

public:

	HUD();

	// Setters
	void updateScore(int score);
	void updateHiScore(int score);
	void storeHiScore();

	// Getters
	int getScore();
	int getHiScore();
	Text getTitle();
	Text getTScore();
	Text getTHiScore();
	Text getSBScore();
	Text getSBHiScore();
	Text getWLP(std::string text);
	RectangleShape getScoreboard();
	RectangleShape getHiScoreboard();
	RectangleShape getNotPlaying();
};
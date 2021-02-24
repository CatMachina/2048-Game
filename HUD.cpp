#include "pch.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include "HUD.h"
#include "TextureHolder.h"

HUD::HUD()
{
	std::fstream instream("gamedata/scores.txt");
	instream >> m_hiScore;
	instream.close();

	m_Font.loadFromFile("fonts/ClearSans-Medium.ttf");
	m_Bold.loadFromFile("fonts/ClearSans-Bold.ttf");
	
	m_Score.setFont(m_Font);
	m_Score.setFillColor(Color::White);
	m_Score.setCharacterSize(CHAR_SIZE_1);
	m_Score.setString("0");
	m_Score.setPosition(390, 110);
	m_Score.setOrigin(m_Score.getLocalBounds().width / 2, m_Score.getLocalBounds().height / 2);

	m_HiScore.setFont(m_Font);
	m_HiScore.setFillColor(Color::White);
	m_HiScore.setCharacterSize(CHAR_SIZE_1);
	
	text << m_hiScore;
	m_HiScore.setString(text.str());
	text.str("");
	m_HiScore.setPosition(545, 110);
	m_HiScore.setOrigin(m_HiScore.getLocalBounds().width / 2, m_HiScore.getLocalBounds().height / 2);

	m_Title.setFont(m_Font);
	m_Title.setPosition(40, 30);
	m_Title.setFillColor(Color::Color(119, 110, 101, 255));
	m_Title.setCharacterSize(CHAR_SIZE_2);
	m_Title.setString("2048");

	m_SBScore.setFont(m_Bold);
	m_SBScore.setFillColor(Color::Color(238, 228, 218, 255));
	m_SBScore.setCharacterSize(CHAR_SIZE_1 - 6);
	m_SBScore.setString("Score");
	m_SBScore.setPosition(390, 70);
	m_SBScore.setOrigin(m_SBScore.getLocalBounds().width / 2, m_SBScore.getLocalBounds().height / 2);

	m_SBHiScore.setFont(m_Bold);
	m_SBHiScore.setFillColor(Color::Color(238, 228, 218, 255));
	m_SBHiScore.setCharacterSize(CHAR_SIZE_1 - 6);
	m_SBHiScore.setString("Best");
	m_SBHiScore.setPosition(545, 70);
	m_SBHiScore.setOrigin(m_SBHiScore.getLocalBounds().width / 2, m_SBHiScore.getLocalBounds().height / 2);

	m_ScoreBoard = RectangleShape(Vector2f(150, 100));
	m_HiScoreBoard = RectangleShape(Vector2f(150, 100));
	m_ScoreBoard.setPosition(315, 50);
	m_HiScoreBoard.setPosition(470, 50);
	m_ScoreBoard.setFillColor(Color::Color(187, 173, 160, 255));
	m_HiScoreBoard.setFillColor(Color::Color(187, 173, 160, 255));

	m_NotPlaying = RectangleShape(Vector2f(625, 925));
	m_NotPlaying.setPosition(0, 0);
	m_NotPlaying.setFillColor(Color::Color(255, 255, 255, 150));

	m_WLP.setFont(m_Bold);
	m_WLP.setCharacterSize(WLP_SIZE);
	m_WLP.setPosition(312.5, 462.5);
	m_WLP.setFillColor(Color::Color(119, 110, 101, 255));
}

void HUD::updateScore(int score)
{
	m_score += score;
	text << m_score;
	m_Score.setString(text.str());
	m_Score.setOrigin(m_Score.getLocalBounds().width / 2, m_Score.getLocalBounds().height / 2);
	text.str("");
}

void HUD::updateHiScore(int score)
{
	m_hiScore = score;
	text << m_hiScore;
	m_HiScore.setString(text.str());
	m_HiScore.setOrigin(m_HiScore.getLocalBounds().width / 2, m_HiScore.getLocalBounds().height / 2);
	text.str("");
}

void HUD::storeHiScore()
{
	std::ofstream out("gamedata/scores.txt");
	out << m_hiScore;
	out.close();
}

int HUD::getScore()
{
	return m_score;
}

int HUD::getHiScore()
{
	return m_hiScore;
}

Text HUD::getTitle()
{
	return m_Title;
}

Text HUD::getTScore()
{
	return m_Score;
}

Text HUD::getTHiScore()
{
	return m_HiScore;
}

Text HUD::getSBScore()
{
	return m_SBScore;
}

Text HUD::getSBHiScore()
{
	return m_SBHiScore;
}

Text HUD::getWLP(string text)
{
	m_WLP.setString(text);
	m_WLP.setOrigin(m_WLP.getLocalBounds().width / 2, m_WLP.getLocalBounds().height / 2);
	return m_WLP;
}

RectangleShape HUD::getScoreboard()
{
	return m_ScoreBoard;
}

RectangleShape HUD::getHiScoreboard()
{
	return m_HiScoreBoard;
}

RectangleShape HUD::getNotPlaying()
{
	return m_NotPlaying;
}
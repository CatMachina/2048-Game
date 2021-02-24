#include "pch.h"
#include "Engine.h"

int main()
{
	Engine engine;
	engine.run();


	/*
	sf::RenderWindow App;
	App.create(sf::VideoMode(800, 600, 32), "Test");
	while (App.isOpen())
	{
		sf::Event e;
		while (App.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				App.close();
				return 0;
			}
		}
		sf::Texture texture;
		texture.loadFromFile("graphics/Board.png");
		sf::Sprite sprite;
		sprite.setTexture(texture);
		App.clear(sf::Color::White);
		App.draw(sprite);
		App.display();
	}
	*/
	
	return 0;
}
#include <Windows.h>
#include "MainHeader.h"
#include "Textures.h"

using namespace sf;
using namespace std;

int main()
{
	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);


	sf::RenderWindow window(sf::VideoMode(SizeX, SizeY), "Bleb n' Babas Tactical", sf::Style::Close);
	//window.setVerticalSyncEnabled(true);
	/* Never use both setVerticalSyncEnabled and setFramerateLimit at the same time! 
	 * They would badly mix and make things worse.*/
	window.setFramerateLimit(120);

	Sprite sprite;
	sprite.setTexture(Textures::getTextureHero());
	sprite.setTextureRect(IntRect(64, 32, 16, 16));
	sprite.setScale(Vector2f(ScaleX, ScaleY));

	Textures::Load();

	Sprite Floor[16][16];
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			Floor[i][j].setTexture(Textures::getTextureHero());
			Floor[i][j].setTextureRect(IntRect(0,0, 16, 16));
			Floor[i][j].setScale(Vector2f(ScaleX, ScaleY));

			Floor[i][j].setPosition(Vector2f(i * 16 * ScaleX, j * 16 * ScaleY));
		}
	}
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;

			case Event::KeyPressed:
				break;

			case Event::JoystickButtonPressed:
				break;
			case Event::JoystickMoved:
				break;

			default:
				break;
			}

			window.clear(Color::Black);
			window.draw(sprite);
			for (int i = 0; i < 16; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					window.draw(Floor[i][j]);
				}
			}

			window.display();
		}
	}

	return 0;
}




void Game()
{
	

}
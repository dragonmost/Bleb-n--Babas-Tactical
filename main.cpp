#include <Windows.h>
#include "MainHeader.h"
#include "TextureManager.h"
#include "SoundManager.h"

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

	TextureManager txtMgr;
	SoundManager soundMgr;

	Music music;
	Sound attack;

	Sprite sprite;
	sprite.setTexture(txtMgr.getTexture("Hero"));
	sprite.setTextureRect(IntRect(64 + 16, 0, 16, 16));
	sprite.setScale(ScaleX, ScaleY);
	

	Sprite Floor[NbTileX][NbTileY];
	for (int i = 0; i < NbTileX; i++)
	{
		for (int j = 0; j < NbTileY; j++)
		{
			Floor[i][j].setTexture(txtMgr.getTexture("Tile"));
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
			
			for (int i = 0; i < NbTileX; i++)
			{
				for (int j = 0; j < NbTileY; j++)
				{
					window.draw(Floor[i][j]);
				}
			}
			window.draw(sprite);
			window.display();
		}
	}

	return 0;
}


void Game()
{
	

}
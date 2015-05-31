#include <Windows.h>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Bleb n' Babas Tactical", sf::Style::Close);
	//window.setVerticalSyncEnabled(true);
	/* Never use both setVerticalSyncEnabled and setFramerateLimit at the same time! 
	 * They would badly mix and make things worse.*/
	window.setFramerateLimit(120);

	Texture texture;
	if (!texture.loadFromFile("image.jpg"))
	{
		cout << "Texture pas loader" << endl;
	}

	Sprite sprite;
	sprite.setTexture(texture);
	

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
			window.display();
		}
	}

	return 0;
}




void Game()
{
	

}



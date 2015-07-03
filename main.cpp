#include <Windows.h>
#include "MainHeader.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include "Cursor.h"
#include "Render.h"

using namespace sf;
using namespace std;

void Game(RenderWindow& window);

int main()
{
	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);
	RenderWindow window;
	window.create(VideoMode(SizeX, SizeY), "Bleb n' Babas Tactical", Style::Close);
	window.setVerticalSyncEnabled(true);

	Render render;
	Cursor MenuCursor(0, 4);

	while (window.isOpen())
	{
		render.Menu(window, MenuCursor.getX(), 0);

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;

			case Event::KeyPressed:
				switch (event.key.code)
				{
				case Keyboard::W:
					MenuCursor.MoveUp();
					break;
				case Keyboard::A:
					MenuCursor.MoveLeft();
					break;
				case Keyboard::S:
					MenuCursor.MoveDown();
					break;
				case Keyboard::D:
					MenuCursor.MoveRight();
					break;
				case Keyboard::Space:
					for (int i = 0; i < SizeX; i += (SizeX / 20))
						render.Menu(window, MenuCursor.getX(), i);
					switch (MenuCursor.getX())
					{
					case 0:	//Continue
						break;
					case 1:	//Load Game
						break;
					case 2:	//New Game
						break;
					case 3:	//Option
						break;
					}
					break;
				}
			default:
				break;
			}
		}
	}

	return 0;
}


void Game(RenderWindow& window)
{
	Render render;
	


}


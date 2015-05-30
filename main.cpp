#include <Windows.h>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Bleb n' Babas Tactical");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

	

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
#include "cScreen.hpp"
#include "Cursor.h"
#include <SFML/Graphics.hpp>

class MenuScreen : public Screen
{
private:
	TextureManager txtMgr;
	SoundManager soundMgr;

public:
	MenuScreen::MenuScreen(void){}
	
	int MenuScreen::Run(RenderWindow &App)
	{
		Event Event;
		bool Running = true;
		Cursor MenuCursor(0, 4);
		Sprite Menu;	//Menu background image
		Sprite cursor;
		int menu = 0;
		bool Enter = false;
		int AnimFrame = 0;
		RectangleShape EnterAnimation(Vector2f(AnimFrame, 32));
		Color rectColor(255, 255, 255, 100);

		Menu.setTexture(txtMgr.getTexture("Main Menu"));
		Menu.setScale(0.5, 0.5);

		cursor.setTexture(txtMgr.getTexture("HandCursor"));
		cursor.scale(2, 2);
	
		while (Running)
		{
			menu = MenuCursor.getX();

			//Verifying events
			while (App.pollEvent(Event))
			{
				// Window closed
				if (Event.type == Event::Closed)
				{
					return (-1);
				}
				//Key pressed
				if (Event.type == Event::KeyPressed && !Enter)
				{
					switch (Event.key.code)
					{
					case Keyboard::W:
					case Keyboard::A:
					case Keyboard::Up:
					case Keyboard::Left:
						MenuCursor.MoveUp();
						break;
					case Keyboard::S:
					case Keyboard::D:
					case Keyboard::Down:
					case Keyboard::Right:
						MenuCursor.MoveDown();
						break;
					case Keyboard::Space:
					case Keyboard::Return:
						Enter = true;
						break;
					case Keyboard::Escape:
						return -1;
						break;
					default:
						break;
					}
				}
			}
			
			cursor.setPosition(220, (menu * 50) + 275);

			if (Enter)
			{
				EnterAnimation.setFillColor(rectColor);
				EnterAnimation.setSize(Vector2f(AnimFrame, 32));
				EnterAnimation.setPosition((SizeX / 2) - (AnimFrame / 2), (MenuCursor.getX() * 50) + 288);
				if (AnimFrame > SizeX)
				{
					txtMgr.deleteAllTextures();
					return(menu + 1);
				}
				AnimFrame += (SizeX / 20);
			}
	
			//Clearing screen
			App.clear();
			//Drawing
			App.draw(Menu);
			App.draw(EnterAnimation);
			App.draw(cursor);
			
			App.display();
		}
	
		//Never reaching this point normally, but just in case, exit the application
		return (-1);
	}
};

#include "cScreen.hpp"
#include <SFML/Graphics.hpp>

class NewGameScreen : public Screen
{
private:
	TextureManager txtMgr;
	SoundManager soundMgr;

public:
	NewGameScreen::NewGameScreen(void){}

	int NewGameScreen::Run(RenderWindow &App)
	{
		Event Event;
		bool Running = true;
		Sprite BG;
		Cursor SelectCursor(0, 0, 13, 5);
		Sprite cursor;
		string name = "Bleb";
		Text Name;
		Text NameN;
		Text NameS;
		Text NameE;
		Text NameW;
		Font font;
		string letter;

		BG.setTexture(txtMgr.getTexture("NewGame"));
		BG.setScale(0.5, 0.5);

		cursor.setTexture(txtMgr.getTexture("HandCursor"));
		//cursor.setTextureRect(IntRect(0, 0, 16, 16));
		cursor.setPosition(80, 210);
		cursor.scale(2.3, 2.3);

		font.loadFromFile("courbd.ttf");
		Name.setFont(font);
		Name.setColor(Color::Black);
		Name.setPosition(Vector2f(10, 10));

		//Outline ... so yea
		NameN.setFont(font);
		NameN.setColor(Color::White);
		NameN.setPosition(Vector2f(10, 10 - 2));
		NameS.setFont(font);
		NameS.setColor(Color::White);
		NameS.setPosition(Vector2f(10, 10 + 2));
		NameE.setFont(font);
		NameE.setColor(Color::White);
		NameE.setPosition(Vector2f(10 - 2, 10));
		NameW.setFont(font);
		NameW.setColor(Color::White);
		NameW.setPosition(Vector2f(10 + 2, 10));
		

		while (Running)
		{
			//Verifying events
			while (App.pollEvent(Event))
			{
				// Window closed
				if (Event.type == Event::Closed)
				{
					return (-1);
				}
				//Key pressed
				if (Event.type == Event::KeyPressed)
				{
					switch (Event.key.code)
					{
					case Keyboard::Up:
						SelectCursor.MoveUp();
						break;
					case Keyboard::Left:
						SelectCursor.MoveLeft();
						break;
					case Keyboard::Down:
						SelectCursor.MoveDown();
						break;
					case Keyboard::Right:
						SelectCursor.MoveRight();
						break;
					case Keyboard::Space:
						letter = CursorChar(SelectCursor.getX(), SelectCursor.getY());
						if (letter == "!")
						{
							if (name.size() > 0)
								name.pop_back();
						}
						else if (letter == "@")
						{
							if (name.size() >= 1)
							{
								txtMgr.deleteAllTextures();
								name.clear();
								return(2);
							}
						}
						else if (name.size() < 10)
							name += letter;
						break;
					case Keyboard::Return:
						if (SelectCursor.getX() == 11 && SelectCursor.getY() == 4)
						{
							txtMgr.deleteAllTextures();
							return (MAPSCREEN);
						}
						else
						{
							SelectCursor.setX(11);
							SelectCursor.setY(4);
						}
						break;
					case Keyboard::BackSpace:
						if (name.size() > 0)
							name.pop_back();
						break;
					case Keyboard::Escape:
						txtMgr.deleteAllTextures();
						name.clear();
						return (0);
					}
				}
				//Text entered
				if (Event.type == sf::Event::TextEntered)
				{
					if (Event.text.unicode > 48 && Event.text.unicode < 122 && name.size() < 10)
						name += static_cast<char>(Event.text.unicode);
				}
			}

			cursor.setPosition((SelectCursor.getX() * 43 ) + 80, (SelectCursor.getY() * 62) + 210);

			Name.setString(name);
			NameN.setString(name);
			NameS.setString(name);
			NameE.setString(name);
			NameW.setString(name);

			App.clear(sf::Color(0, 0, 0, 0));

			App.draw(BG);
			App.draw(NameN);
			App.draw(NameS);
			App.draw(NameE);
			App.draw(NameW);
			App.draw(Name);
			App.draw(cursor);

			App.display();
		}
		return -1;
	}

	string CursorChar(int _X, int _Y)
	{
		static const char* chrRow1[]{ "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M" };
		static const char* chrRow2[]{ "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
		static const char* chrRow3[]{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c" };
		static const char* chrRow4[]{ "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p" };
		static const char* chrRow5[]{ "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "!", "@", "@" };

		string result;

		switch (_Y)
		{
		case 0:
			result = string(chrRow1[_X]);
			break;
		case 1:
			result = string(chrRow2[_X]);
			break;
		case 2:
			result = string(chrRow3[_X]);
			break;
		case 3:
			result = string(chrRow4[_X]);
			break;
		case 4:
			result = string(chrRow5[_X]);
			break;
		}

		return result;
	}

};
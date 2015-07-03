using namespace sf;
using namespace std;

class Render
{
private:
	int anim = 0;
	
	TextureManager txtMgr;
	SoundManager soundMgr;


public:
	Render()
	{
		
	}

	void Menu(RenderWindow& _window, int _CursorPos, int _Enter)
	{
		Sprite Menu;
		Menu.setTexture(txtMgr.getTexture("Main Menu"));
		Menu.scale(0.5, 0.5);

		Sprite Cursor;
		Cursor.setTexture(txtMgr.getTexture("HandCursor"));
		Cursor.scale(2, 2);
		Cursor.setPosition(220, (_CursorPos * 50) + 275);

		RectangleShape EnterAnimation(Vector2f(_Enter, 32));
		Color rectColor(255, 255, 255, 100);
		EnterAnimation.setFillColor(rectColor);
		EnterAnimation.setPosition((SizeX / 2) - (_Enter / 2), (_CursorPos * 50) + 285);
		
		//EnterAnimation.setPosition(220, ((_CursorPos)* 50) + 275);

		
		_window.clear(Color::Black);

		_window.draw(Menu);
		//if (_Enter )
			_window.draw(EnterAnimation);
		_window.draw(Cursor);

		_window.display();
	}


	void Map(Sprite _Backgound[NbTileX][NbTileY], Sprite _Obstacle[NbTileX][NbTileY], GoundValue _GroundValue[NbTileX][NbTileY])
	{

	}



//};

bool render()
{
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
			Floor[i][j].setTextureRect(IntRect(0, 0, 16, 16));
			Floor[i][j].setScale(Vector2f(ScaleX, ScaleY));

			Floor[i][j].setPosition(Vector2f(i * 16 * ScaleX, j * 16 * ScaleY));
		}
	}

	Cursor cursor = Cursor(7, 5, NbTileX, NbTileY);
	Sprite sprCursor;
	sprCursor.setTexture(txtMgr.getTexture("UI"));
	sprCursor.setTextureRect(IntRect(0, 0, 16, 16));
	sprCursor.setScale(Vector2f(ScaleX, ScaleY));
	sprCursor.setPosition(Vector2f(cursor.getX() * 16 * ScaleX, cursor.getY() * 16 * ScaleY));
	sprCursor.setColor(Color::Blue);

	RectangleShape Menu(Vector2f(SizeX, SizeY));
	Menu.setTexture(&txtMgr.getTexture("UI"));
	Menu.setTextureRect(IntRect(16, 0, 16, 16));
	//Menu.setScale(Vector2f(ScaleX, ScaleY));

	Text MenuText;
	Font font;
	font.loadFromFile("MorrisRomanBlack.ttf");
	MenuText.setString("Menu");
	MenuText.setFont(font);
	MenuText.setColor(Color::Red);
	MenuText.setPosition(120, 50);

	//worst animation ever
	Sprite Crystal1;
	Crystal1.setTexture(txtMgr.getTexture("UI"));
	Crystal1.setTextureRect(IntRect(2 * 16, 0, 16, 16));
	Crystal1.setScale(Vector2f(ScaleX, ScaleY));
	Crystal1.setPosition(100, 100);
	Sprite Crystal2;
	Crystal2.setTexture(txtMgr.getTexture("UI"));
	Crystal2.setTextureRect(IntRect(3 * 16, 0, 16, 16));
	Crystal2.setScale(Vector2f(ScaleX, ScaleY));
	Crystal2.setPosition(100, 100);
	Sprite Crystal3;
	Crystal3.setTexture(txtMgr.getTexture("UI"));
	Crystal3.setTextureRect(IntRect(3 * 16, 0, 16, 16));
	Crystal3.setScale(Vector2f(ScaleX, -ScaleY));
	Crystal3.setPosition(100, 148);
	Sprite Crystal4;
	Crystal4.setTexture(txtMgr.getTexture("UI"));
	Crystal4.setTextureRect(IntRect(4 * 16, 0, 16, 16));
	Crystal4.setScale(Vector2f(ScaleX, ScaleY));
	Crystal4.setPosition(100, 100);

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
				switch (event.key.code)
				{
				case Keyboard::W:
					cursor.MoveUp();
					break;
				case Keyboard::A:
					cursor.MoveLeft();
					break;
				case Keyboard::S:
					cursor.MoveDown();
					break;
				case Keyboard::D:
					cursor.MoveRight();
					break;
				case Keyboard::Space:
					cursor.Select();
					if (cursor.getX() == sprite.getPosition().x && cursor.getY() == sprite.getPosition().y)
					if (cursor.getSelectState())
						sprCursor.setColor(Color::Green);
					else
						sprCursor.setColor(Color::Blue);
					break;
				}
				sprCursor.setPosition(Vector2f(cursor.getX() * 16 * ScaleX, cursor.getY() * 16 * ScaleY));
				if (cursor.getSelectState())
					sprite.setPosition(sprCursor.getPosition().x, sprCursor.getPosition().y);
				break;

			case Event::JoystickButtonPressed:
				switch (event.joystickButton.button)
				{
				case 12:	//UP
					cursor.MoveUp();
					break;
				case 13:	//RIGHT
					cursor.MoveRight();
					break;
				case 14:	//Down
					cursor.MoveDown();
					break;
				case 15:	//LEFT
					cursor.MoveLeft();
					break;
				}
				sprCursor.setPosition(Vector2f(cursor.getX() * 16 * ScaleX, cursor.getY() * 16 * ScaleY));
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
			window.draw(sprCursor);

			//window.draw(Menu);
			//window.draw(MenuText);
			if (anim < 10)
				window.draw(Crystal1);
			else if (anim < 20 && anim >= 10)
				window.draw(Crystal2);
			else if (anim < 30 && anim >= 20)
				window.draw(Crystal3);
			else if (anim < 40 && anim >= 30)
				window.draw(Crystal4);
			else 
				anim = 0;

			anim = anim + 1;

			window.display();
		}
	}
	return false;
}

};
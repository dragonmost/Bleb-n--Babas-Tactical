#include <cmath>
#include "cScreen.hpp"
#include"Area.h"
#include "AnimatedSprite.hpp"

class MapScreen : public Screen
{
private:
	TextureManager txtMgr;
	SoundManager soundMgr;

public:
	MapScreen::MapScreen(void){}

	int MapScreen::Run(RenderWindow &App)
	{
		Event Event;
		bool Running = true;
		Sprite Map;
		CListDCwCur<Area*>* ListArea = new CListDCwCur<Area*>();
		LoadAreaList(ListArea);
		Sprite cursor;
		Sprite* Areas;
		int NbArea;
		Text AreaName;
		Font AreaFont;
		RectangleShape AreaRect;
		bool Enter = false;

		
		Map.setTexture(txtMgr.getTexture("Map"));
		Map.setScale(0.5, 0.5);
		Map.getPosition();

		//Animation for the CharPosition Cursor
		Animation CharAnim;
		CharAnim.setSpriteSheet(txtMgr.getTexture("UI"));
		CharAnim.addFrame(IntRect(32, 16, 16, 16));
		CharAnim.addFrame(IntRect(48, 16, 16, 16));
		CharAnim.addFrame(IntRect(64, 16, 16, 16));
		CharAnim.addFrame(IntRect(80, 16, 16, 16));
		CharAnim.addFrame(IntRect(96, 16, 16, 16));
		CharAnim.addFrame(IntRect(112, 16, 16, 16));

		AnimatedSprite CharSprite(seconds(0.2));
		CharSprite.setPosition(100, 100 - 16);


		cursor.setTexture(txtMgr.getTexture("HandCursor"));
		cursor.scale(2, 2);

		//Setup the Area Sprites
		NbArea = ListArea->ObtenirCompte();
		Areas = new Sprite[ListArea->ObtenirCompte()];
		ListArea->AllerPremier();
		for (int i = 0; i < NbArea; i++)
		{
			Area* addedArea = ListArea->Obtenir();
			Areas[i].setPosition(addedArea->getX(), addedArea->getY());
			Areas[i].setTexture(txtMgr.getTexture("UI"));
			Areas[i].setTextureRect(IntRect(16, 16 ,16 ,16));
			
			switch (addedArea->getState())
			{
				//colors not determined yet
			case WILD:
				Areas[i].setColor(Color::Green);
				break;
			case CITY:
				Areas[i].setTextureRect(IntRect(0, 16, 16, 16));
				Areas[i].setColor(Color::Blue);
				break;
			case ALLIED:
				Areas[i].setColor(Color::Blue);
				break;
			case HOSTILE:
				Areas[i].setColor(Color::Red);
				break;
			}

			ListArea->AllerSuivant();
		}
		ListArea->AllerPremier();
		
		//Background map
		Map.setTexture(txtMgr.getTexture("Map"));
		Map.setScale(0.5, 0.5);

		//Area name
		AreaFont.loadFromFile("courbd.ttf");
		AreaName.setFont(AreaFont);
		AreaRect.setFillColor(Color(0, 0, 0, 150));


		Clock frameClock;	//Clock for the Animations
		Time frameTime;		//Time for the Animations

		Area* area = ListArea->Obtenir();
		while (Running)
		{
			frameTime = frameClock.restart();
			//Verifying events
			while (App.pollEvent(Event) && !Enter)
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
					case Keyboard::W:
					case Keyboard::D:
					case Keyboard::Up:
					case Keyboard::Right:
						ListArea->AllerSuivant();
						break;
					case Keyboard::S:
					case Keyboard::A:
					case Keyboard::Down:
					case Keyboard::Left:
						ListArea->AllerPrecedent();
						break;
					case Keyboard::Space:
					case Keyboard::Return:
						//will move your character to the desired location
						//If on the same city as your character it opens the City Menu
						Enter = true;
						break;
					case Keyboard::Escape:
						//will open a menu to check inventory save/load game etc
						break;
					}
				}

				area = ListArea->Obtenir();
				AreaRect.setSize(Vector2f(AreaName.getString().getSize() * 8, 20)); 
				AreaRect.setPosition(area->getX() - (AreaRect.getSize().x / 2), area->getY());
			}

			if (Enter)
				Enter = MoveChar(ListArea, CharSprite, *area, frameClock);

			CharSprite.play(CharAnim);
			CharSprite.update(frameTime);
			//CharSprite.setPosition(area->getX(), area->getY() - 16);
			cursor.setPosition(area->getX() - 64, area->getY() - 32);

			App.clear();

			App.draw(Map);
			for (int i = 0; i < ListArea->ObtenirCompte(); i++)
			{
				App.draw(Areas[i]);
			}
			App.draw(CharSprite);
			App.draw(cursor);

			App.display();
		}
		

		return -1;
	}

	void LoadAreaList(CListDCwCur<Area*>* List)
	{
		List->Ajouter(new Area("Test", 100, 100, CITY));
		List->Ajouter(new Area("Test", 100, 500, HOSTILE));
		List->Ajouter(new Area("Test", 350, 350, WILD));
		List->Ajouter(new Area("Test", SizeX - 50, 75, ALLIED));
	}

	void MoveChar(CListDCwCur<Area*>* ListArea, Sprite &sprite, Area Destination, Clock clock)
	{
		/*
		int X = sprite.getPosition().x;
		int Y = sprite.getPosition().y;
		float speed = 300.f;
		float delta = clock.restart().asSeconds();

		sprite.move(speed * delta, speed * delta);

		int deltaX = sprite.getPosition().x - Destination.getX();
		int deltaY = sprite.getPosition().y - Destination.getY();
		float m = deltaY / deltaX;
		float speed = 300.f;
		float delta = clock.restart().asSeconds();

		sprite.move(-deltaX / 100, -deltaY / 100);
		*/
	}
	bool MoveChar(CListDCwCur<Area*>* ListArea, AnimatedSprite &sprite, Area Destination, Clock clock)
	{
		//http://gamedev.stackexchange.com/questions/23447/moving-from-ax-y-to-bx1-y1-with-constant-speed
		float X1 = sprite.getPosition().x;
		float Y1 = sprite.getPosition().y;
		float X2 = Destination.getX();
		float Y2 = Destination.getY() - 16;
		float speed = 200.f;
		float delta = clock.getElapsedTime().asSeconds();
		float distance = sqrt(pow(X2 - X1, 2) + pow(Y2 - Y1, 2));
		float directionX = (X2 - X1);
		float directionY = (Y2 - Y1);

		sprite.move((directionX * speed) * delta, (directionY * speed) * delta);

		if (round(X1) != round(X2) && round(Y1) != round(Y2))
			return true;
		else
			return false;
	}

};
#include "cScreen.hpp"
#include"Area.h"

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
		Sprite CharSprite;
		CListDCwCur<Area*>* ListArea = new CListDCwCur<Area*>();
		LoadAreaList(ListArea);
		Sprite cursor;
		Sprite* Areas;
		int NbArea;
		Text AreaName;
		Font AreaFont;
		RectangleShape AreaRect;
		
		Map.setTexture(txtMgr.getTexture("Map"));
		Map.setScale(0.5, 0.5);
		Map.getPosition();

		CharSprite.setTexture(txtMgr.getTexture("UI"));
		CharSprite.setTextureRect(IntRect(32,16,16,16));

		cursor.setTexture(txtMgr.getTexture("HandCursor"));
		cursor.scale(2, 2);

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
		
		Map.setTexture(txtMgr.getTexture("Map"));
		Map.setScale(0.5, 0.5);

		AreaFont.loadFromFile("courbd.ttf");
		AreaName.setFont(AreaFont);
		AreaRect.setFillColor(Color(0, 0, 0, 150));

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
						break;
					case Keyboard::Escape:
						//will open a menu to check inventory save/load game etc
						break;
					}
				}
				Area* area = ListArea->Obtenir();

				CharSprite.setPosition(area->getX(), area->getY() - 16);
				cursor.setPosition(area->getX() - 64, area->getY() - 32);

				AreaRect.setSize(Vector2f(AreaName.getString().getSize() * 8, 20)); 
				AreaRect.setPosition(area->getX() - (AreaRect.getSize().x / 2), area->getY());
			}

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
	}
};
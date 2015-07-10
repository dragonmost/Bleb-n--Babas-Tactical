#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include "CelluleListe.h"
#include "ListDCwCur.h"
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
		CListDCwCur<Area*>* ListArea = new CListDCwCur<Area*>();
		Sprite cursor;
		Sprite* Areas;
		int NbArea;
		
		Map.setTexture(txtMgr.getTexture("Map"));
		Map.setScale(0.5, 0.5);

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
			Areas[i].setTextureRect(IntRect());
			
			switch (addedArea->getState())
			{
				//colors not determined yet
			case WILD:
				Areas[i].setColor(Color::Green);
				break;
			case CITY:
				Areas[i].setTextureRect(IntRect());
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
		
		Map.setTexture(txtMgr.getTexture("Map"));
		Map.setScale(0.5, 0.5);

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
					case Keyboard::A:
					case Keyboard::Up:
					case Keyboard::Left:
						ListArea->AllerSuivant();
						break;
					case Keyboard::S:
					case Keyboard::D:
					case Keyboard::Down:
					case Keyboard::Right:
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
				cursor.setPosition(ListArea->Obtenir()->getX(), ListArea->Obtenir()->getY());

			}

			App.clear();

			App.draw(Map);
			for (int i = 0; i < ListArea->ObtenirCompte(); i++)
			{
				App.draw(Areas[i]);
			}
			App.draw(cursor);

			App.display();
		}
		
		

		return -1;
	}
};
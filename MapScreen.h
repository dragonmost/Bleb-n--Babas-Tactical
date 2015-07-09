#include "cScreen.hpp"
#include <SFML/Graphics.hpp>

class MapScreen : public Screen
{
private:
	TextureManager txtMgr;
	SoundManager soundMgr;

public:
	MapScreen::MapScreen(void){}

	int MapScreen::Run(RenderWindow &App)
	{
		Sprite Map;


		Map.setTexture(txtMgr.getTexture("Map"));
		Map.setScale(0.5, 0.5);


		return -1;
	}
};
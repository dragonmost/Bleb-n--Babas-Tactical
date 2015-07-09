#include <Windows.h>
#include "MainHeader.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include "cScreen.hpp"



using namespace sf;
using namespace std;

int main(int argc, char** argv)
{
	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);

	//Applications variables
	vector<Screen*> Screens;
	int screen = 0;

	//Window creation
	RenderWindow window(VideoMode(SizeX, SizeY), "Bleb n' Babas Tactical", Style::Close);
	window.setVerticalSyncEnabled(true);

	
	//Mouse cursor no more visible
	window.setMouseCursorVisible(false);

	//Screens preparations
	MenuScreen menuScreen;
	Screens.push_back(&menuScreen);
	MapScreen mapScreen;
	Screens.push_back(&mapScreen);
	/*LoadScreen*/GameScreen loadScreen;
	Screens.push_back(&loadScreen);
	NewGameScreen newGameScreen;
	Screens.push_back(&newGameScreen);
	/*OptionScreen*/GameScreen optionScreen;
	Screens.push_back(&optionScreen);
	GameScreen gameScreen;
	Screens.push_back(&gameScreen);
	

	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(window);
	}

	return 0;
	

}


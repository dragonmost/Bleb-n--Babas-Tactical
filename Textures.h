#include <SFML/Graphics.hpp>
#include <iostream>
/*
using namespace sf;
using namespace std;

class Textures
{
private:
	static Texture Hero;
	static Texture Dungeon_Floor;
public:
	static void Load();
	static Texture getTextureHero();
	static Texture getTextureDungeon_Floor();
};

*/
using namespace sf;

static Texture Hero;

class Textures
{
private:
	Texture Hero;
	Texture Dungeon_Floor;

public:
	Textures()
	{
		Hero.loadFromFile("image.jpg");
	}

	Texture getHero()
	{
		return Hero;
	}

};
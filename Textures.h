#include <SFML/Graphics.hpp>
#include <iostream>

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
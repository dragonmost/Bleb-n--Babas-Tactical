#include "TextureManager.h"
#include "Classes.h"
#include "Races.h"

using namespace std;
using namespace sf;

class Character
{
private:
	string Name;
	int Level;
	Classes classname;
	Races RaceName;
	int baseHP;
	int baseMana;
	int baseSpeed;
	int baseStrenght;
	int baseMind;
	int Bravery;
	int Faith;
	string TextureName;

	int PosX;
	int PosY;
	

public:
	Character(string _Name, int _Level, int _HP, int _Mana, int _Speed, int _Strenght, int _Mind, int _Bravery, int _Faith, string _txtname)
	{
		Name = _Name;
		Level = _Level;
		baseHP = _HP;
		baseMana = _Mana;
		baseSpeed = _Speed;
		baseStrenght = _Strenght;
		baseMind = _Mind;
		Bravery = _Bravery;
		Faith = _Faith;
		TextureName = _txtname;
	}

	string getName()
	{
		return Name;
	}

	int getHP()
	{
		return baseHP;
	}

	int getMane()
	{
		return baseMana;
	}

	int getLevel()
	{
		return Level;
	}

	int getSpeed()
	{
		return baseSpeed;
	}

	int getStrenght()
	{
		return baseStrenght;
	}

	int getMind()
	{
		return baseMind;
	}

	int getFaith()
	{
		return Faith;
	}

	int getBravery()
	{
		return Bravery;
	}

	string getTexureName()
	{
		return TextureName;
	}
};
#include "TextureManager.h"
#include "CelluleListe.h"
#include "ListDCwCur.h"

using namespace std;
using namespace sf;

class CharStat
{
private:
	int HP;
	int Mana;
	int Speed;
	int Strenght;
	int Defence;
	int Mind;
	int Bravery;
	int Faith;

public:
	CharStat()
	{
		HP = 100;
		Mana = 100;
		Speed = 1;
		Strenght = 1;
		Defence = 1;
		Mind = 1;
		Bravery = 50;
		Faith = 50;
	}

	CharStat(int _HP, int _Mana, int _Speed, int _Strenght, int _Defence, int _Mind, int _Bravery, int _Faith)
	{
		HP = _HP;
		Mana = _Mana;
		Speed = _Speed;
		Strenght = _Strenght;
		Defence = _Defence;
		Mind = _Mind;
		Bravery = _Bravery;
		Faith = _Faith;
	}

	int getHP()
	{
		return HP;
	}

	int getMana()
	{
		return Mana;
	}

	int getSpeed()
	{
		return Speed;
	}

	int getStrenght()
	{
		return Strenght;
	}

	int getDefence()
	{
		return Defence;
	}

	int getMind()
	{
		return Mind;
	}

	int getFaith()
	{
		return Faith;
	}

	int getBravery()
	{
		return Bravery;
	}
};
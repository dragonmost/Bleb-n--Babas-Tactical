#include "TextureManager.h"
#include "Job.h"
#include "Race.h"
#include "CelluleListe.h"
#include "ListDCwCur.h"

using namespace std;
using namespace sf;

class Character
{
private:
	string Name;
	int Level;
	Job classname;
	Race RaceName;
	int baseHP;
	int baseMana;
	int baseSpeed;
	int baseStrenght;
	int baseDefence;
	int baseMind;
	int Bravery;
	int Faith;
	//CListDCwCur<Stat>* lstStat = new CListDCwCur<Stat>();		//list of base stat instead
	//CListDCwCur<Stat>* lstBuff = new CListDCwCur<Stat>();		//list of buff stat
	//CListDCwCur<Equipe>* lstBuff = new CListDCwCur<Equipe>();	//list of item equiped
	string TextureName;

	int PosX;
	int PosY;
	
public:
	Character(string _Name, int _Level, int _HP, int _Mana, int _Speed, int _Strenght, int _Defence, int _Mind, int _Bravery, int _Faith, string _txtname)
	{
		Name = _Name;
		Level = _Level;
		baseHP = _HP;
		baseMana = _Mana;
		baseSpeed = _Speed;
		baseStrenght = _Strenght;
		baseDefence = _Defence;
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

	int getDefence()
	{
		return baseDefence;
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
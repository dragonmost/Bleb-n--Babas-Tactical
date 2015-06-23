#include "TextureManager.h"
#include "Job.h"
#include "Race.h"
#include "CelluleListe.h"
#include "ListDCwCur.h"
#include "CharStat.h"

using namespace std;
using namespace sf;

class Character
{
private:
	string Name;
	int Level;
	Job classname;
	Race RaceName;
	CharStat baseStat;
	//CListDCwCur<Stat>* lstStat = new CListDCwCur<Stat>();		//list of base stat instead
	//CListDCwCur<Stat>* lstBuff = new CListDCwCur<Stat>();		//list of buff stat
	//CListDCwCur<Equipe>* lstBuff = new CListDCwCur<Equipe>();	//list of item equiped
	string TextureName;

	int PosX;
	int PosY;
	
public:
	Character(string _Name, int _Level, CharStat _baseStat, string _txtname)
	{
		Name = _Name;
		Level = _Level;
		baseStat = _baseStat;
		TextureName = _txtname;
	}

	string getName()
	{
		return Name;
	}

	int getLevel()
	{
		return Level;
	}

	int getHP()
	{
		return baseStat.getHP();
	}

	int getMane()
	{
		return baseStat.getMana();
	}

	int getSpeed()
	{
		return baseStat.getSpeed();
	}

	int getStrenght()
	{
		return baseStat.getStrenght();
	}

	int getDefence()
	{
		return baseStat.getDefence();
	}

	int getMind()
	{
		return baseStat.getMind();
	}

	int getBravery()
	{
		return baseStat.getBravery();
	}

	int getFaith()
	{
		return baseStat.getFaith();
	}

	string getTexureName()
	{
		return TextureName;
	}
};
#include "Character.h"

class Team
{
private:
	vector<Character> TeamMember;

public:
	Team(int _TeamSize)
	{
		TeamMember.resize(_TeamSize);
	}


};
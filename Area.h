
class Area
{
private:
	string Name;
	int X, Y;
	AreaState State;

public:
	Area(string _Name, int _X, int _Y, AreaState _State)
	{
		Name = _Name;
		X = _X;
		Y = _Y;
		State = _State;
	}

	string getName()
	{ return Name; }

	int getX()
	{ return X; }
	
	int getY()
	{ return Y; }

	AreaState getState()
	{ return State; }

};
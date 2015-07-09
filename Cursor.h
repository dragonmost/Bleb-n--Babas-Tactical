class Cursor
{
private:
	int X, Y;
	int MaxX, MaxY;
	bool boSelect;

public:
	Cursor(int _X, int _Y, int _MaxX, int _MaxY)
	{
		X = _X;
		Y = _Y;
		MaxX = _MaxX;
		MaxY = _MaxY;
		boSelect = false;
	}

	Cursor(int _X, int _MaxX)
	{
		X = _X;
		MaxX = _MaxX;

		Y = -1;
	}


	void MoveUp()
	{
		if (Y == -1)
		{
			if (X == 0)
				X = MaxX -1;
			else
				X--;
		}
		else
		{
			if (Y > 0)
				Y--;
		}
	}

	void MoveDown()
	{
		if (Y == -1)
		{
			if (X == MaxX - 1)
				X = 0;
			else
				X++;
		}
		else
		{
			if (Y < MaxY - 1)
				Y++;
		}
	}

	void MoveRight()
	{
		if (Y == -1)
		{
			if (X == MaxX - 1)
				X = 0;
			else
				X++;
		}
		else
		{
			if (X < MaxX - 1)
				X++;
		}
	}

	void MoveLeft()
	{
		if (Y == -1)
		{
			if (X == 0)
				X = MaxX -1;
			else
				X--;
		}
		else
		{
			if (X > 0)
				X--;
		}
	}

	void Select()
	{ boSelect = !boSelect; }

	bool getSelectState()
	{ return boSelect; }

	int getX()
	{ return X; }

	int getY()
	{ return Y; }

	void setX(int _X)
	{ 
		if (_X < MaxX)
			X = _X;
		else
			X = MaxX -1;
	}

	void setY(int _Y)
	{ 
		if (_Y < MaxY)
			Y = _Y;
		else
			Y = MaxY -1;
	}

};
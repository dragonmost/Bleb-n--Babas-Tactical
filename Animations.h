
using namespace sf;

class Animations
{
private:
	CFileCirc<IntRect*>* AnimationFrames = new CFileCirc<IntRect*>();

public:
	void addFrame(IntRect* _frame)
	{
		AnimationFrames->Enfiler(_frame);
	}

	IntRect* getFrame()
	{
		IntRect* frame = AnimationFrames->Defiler();
		AnimationFrames->Enfiler(frame);
		return frame;
	}



};

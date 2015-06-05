#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class SoundManager
{
private:
	SoundManager(const SoundManager&);
	SoundManager& operator =(const SoundManager&);

	map<string, SoundBuffer > sounds;

public:
	SoundManager()
	{

	}

	const SoundBuffer& getSoundBuffer(const string& _filename)
	{
		for (map<string, SoundBuffer>::const_iterator i = sounds.begin(); i != sounds.end(); i++)
		{
			if (_filename == i->first)
			{
				return i->second;
			}
		}

		SoundBuffer soundBuffer;

		if (soundBuffer.loadFromFile(".\\Textures\\" + _filename + ".ogg"))
		{
			sounds[_filename] = soundBuffer;
			return sounds[_filename];
		}

		sounds[_filename] = soundBuffer;
		return sounds[_filename];
	}

	void deleteSoundBuffer(const SoundBuffer& _sound)
	{
		for (map<string, SoundBuffer>::const_iterator i = sounds.begin(); i != sounds.end(); i++)
		{
			if (&_sound == &i->second)
			{
				sounds.erase(i);
				return;
			}
		}
	}

	void deleteSoundBuffer(const string _filename)
	{
		map<string, SoundBuffer>::const_iterator i = sounds.find(_filename);
		if (i != sounds.end())
			sounds.erase(i);
	}

	~SoundManager()
	{

	}

};
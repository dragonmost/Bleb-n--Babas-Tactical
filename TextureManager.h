#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class TextureManager
{
private:
	TextureManager(const TextureManager&);
	TextureManager& operator =(const TextureManager&);

	map<string, Texture > textures;

public:
	TextureManager()
	{

	}

	const Texture& getTexture(const string& _filename)
	{
		for (map<string, Texture>::const_iterator i = textures.begin(); i != textures.end(); i++)
		{
			if (_filename == i->first)
			{
				return i->second;
			}
		}

		Texture texture;
		if (texture.loadFromFile(".\\Textures\\My Work\\" + _filename + ".png"))
		{
			textures[_filename] = texture;
			return textures[_filename];
		}

		textures[_filename] = texture;
		return textures[_filename];
	}

	void deleteTexture(const Texture& _texture)
	{
		for (map<string, Texture>::const_iterator i = textures.begin(); i != textures.end(); i++)
		{
			if (&_texture == &i->second)
			{
				textures.erase(i);
				return;
			}
		}
	}

	void deleteTexture(const string _filename)
	{
		map<string, Texture>::const_iterator i = textures.find(_filename);
		if (i != textures.end())
			textures.erase(i);
	}

	void deleteAllTextures()
	{
		textures.clear();
	}

	~TextureManager()
	{

	}

};
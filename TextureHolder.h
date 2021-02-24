#pragma once
#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;
using namespace std;

class TextureHolder
{
private:
	
	// Map texture file name to texture
	map<string, Texture> m_Textures;
	// To call static getTexture function
	static TextureHolder* m_s_Instance;

public:
	
	// Constructor
	TextureHolder();
	// Assign texture function
	static Texture& getTexture(string const& filename);

};
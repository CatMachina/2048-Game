#include "pch.h"
#include "TextureHolder.h"
#include <assert.h>

#include <iostream>

using namespace sf;
using namespace std;

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder()
{
	// Tbh, idk rlly know what this does and I should find out
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

Texture& TextureHolder::getTexture(string const& filename)
{
	auto& m = m_s_Instance->m_Textures;
	// Use iterator to see if texture already exists or not
	auto key = m.find(filename);
	if (key != m.end())
	{
		// If exists return texture
		return key->second;
	}
	else
	{
		auto& texture = m[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}

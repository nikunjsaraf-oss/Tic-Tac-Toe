#include "AssetManager.h"

namespace Nikunj
{
	void AssetManager::LoadTexture(std::string textureName, std::string fileName)
	{
		sf::Texture texture;

		if (texture.loadFromFile(fileName))
		{
			this->_textures[textureName] = texture;
		}
	}

	sf::Texture &AssetManager::GetTexture(std::string textureName)
	{
		return this->_textures.at(textureName);
	}

	void Nikunj::AssetManager::LoadFont(std::string fontName, std::string fileName)
	{
		sf::Font font;

		if (font.loadFromFile(fileName))
		{
			this->_fonts[fontName] = font;
		}
	}

	sf::Font &Nikunj::AssetManager::GetFont(std::string fontName)
	{
		return this->_fonts.at(fontName);
	}
}

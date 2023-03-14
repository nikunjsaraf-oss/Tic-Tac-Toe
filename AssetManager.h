#pragma once

#include <map>
#include<SFML/Graphics.hpp>

namespace Nikunj {
	class AssetManager
	{
	public :
		AssetManager() {}
		~AssetManager() {}

		void LoadTexture(std::string textureName, std::string fileName);
		sf::Texture& GetTexture(std::string textureName);

		void LoadFont(std::string fontName, std::string fileName);
		sf::Font& GetFont(std::string fontName);


	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;

	};
}


#pragma once

#include<SFML/Graphics.hpp>

namespace Nikunj
{
	class InputManager
	{
	public: 
		InputManager(){}
		~InputManager(){}

		bool IsSpriteClicked(sf::Sprite spriteObject, sf::Mouse::Button mouseButton, sf::RenderWindow& renderWindow);
		sf::Vector2i GetMousePosition(sf::RenderWindow& renderWindow);
	};
}


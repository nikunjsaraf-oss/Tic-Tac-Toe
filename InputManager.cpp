#include "InputManager.h"

namespace Nikunj
{
	bool InputManager::IsSpriteClicked(sf::Sprite spriteObject, sf::Mouse::Button mouseButton, sf::RenderWindow& renderWindow)
	{
		if (sf::Mouse::isButtonPressed(mouseButton))
		{
			sf::IntRect tempRect(spriteObject.getPosition().x, spriteObject.getPosition().y, spriteObject.getGlobalBounds().width, spriteObject.getGlobalBounds().height);

			if (tempRect.contains(sf::Mouse::getPosition(renderWindow)))
			{
				return true;
			}
		}
		return false;
	}

	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& renderWindow)
	{
		return sf::Mouse::getPosition(renderWindow);
	}
}

#include<sstream>
#include<iostream>

#include "SplashState.h"
#include "Definitions.h"

namespace Nikunj
{
	SplashState::SplashState(GameDataRef data)
	{
		_data = data;
	}

	void SplashState::Init()
	{
		this->_data->assetManager.LoadTexture("Splash Screen Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assetManager.GetTexture("Splash Screen Background"));
	}

	void SplashState::HandleInput()
	{
		sf::Event event;
		while (this->_data->renderWindow.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->renderWindow.close();
			}
		}
	}
	void SplashState::Update(float dt)
	{
		if (this->clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			// Switch to main menu
			std::cout << "Go to main menu";
		}
	}

	void SplashState::Draw(float dt)
	{
		this->_data->renderWindow.clear(sf::Color::Red);
		this->_data->renderWindow.draw(this->_background);
		this->_data->renderWindow.display();
	}
}
#include<sstream>
#include<iostream>

#include "GameOverState.h"
#include "Definitions.h"
#include "MainMenuState.h"
#include "GameState.h"

namespace Nikunj
{
	GameOverState::GameOverState(GameDataRef data) :_data(data)
	{

	}

	void GameOverState::Init()
	{

		this->_data->assetManager.LoadTexture("Retry Button", RETRY_BUTTON);
		this->_data->assetManager.LoadTexture("Home Button", HOME_BUTTON);

		this->_retryButton.setTexture(this->_data->assetManager.GetTexture("Retry Button"));
		this->_homeButton.setTexture(this->_data->assetManager.GetTexture("Home Button"));

		this->_retryButton.setPosition((this->_data->renderWindow.getSize().x / 2.0f) - (this->_retryButton.getLocalBounds().width / 2.0f),
			(this->_data->renderWindow.getSize().y / 3.0f) - (this->_retryButton.getLocalBounds().height / 2.0f));

		this->_homeButton.setPosition((this->_data->renderWindow.getSize().x / 2.0f) - (this->_homeButton.getLocalBounds().width / 2.0f),
			(this->_data->renderWindow.getSize().y / 3.0f * 2.0f) - (this->_homeButton.getLocalBounds().height / 2.0f));
	}

	void GameOverState::HandleInput()
	{
		sf::Event event;
		while (this->_data->renderWindow.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->renderWindow.close();
			}

			if (this->_data->inputManager.IsSpriteClicked(this->_retryButton, sf::Mouse::Left, this->_data->renderWindow))
			{
				this->_data->machine.AddState(StateRef(new GameState(_data)), true);
			}

			if (this->_data->inputManager.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->renderWindow))
			{
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
		}
	}

	void GameOverState::Update(float dt)
	{

	}

	void GameOverState::Draw(float dt)
	{
		this->_data->renderWindow.clear(sf::Color::Red);
		//this->_data->renderWindow.clear(sf::Color{ 242,214,83,255 });

		this->_data->renderWindow.draw(this->_retryButton);
		this->_data->renderWindow.draw(this->_homeButton);

		this->_data->renderWindow.display();
	}

}
